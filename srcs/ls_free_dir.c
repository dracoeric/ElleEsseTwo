/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_free_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:35:45 by erli              #+#    #+#             */
/*   Updated: 2019/11/29 16:43:39 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

 #include "libft.h"

/*
** Frees all the argument file list elements.
*/

static	void	ls_free_path_list(t_ls_dir_list *node)
{
	t_ls_path_list *bubble;
	t_ls_path_list *tmp;

	bubble = node->flist;
	while (bubble != 0)
	{
		if (bubble->info->allocated == 1)
			free(bubble->info->pathname);
		free(bubble->info);
		tmp = bubble;
		bubble = bubble->next;
		free(tmp);
	}
	node->flist = 0;
}

/*
** Free the dir_list node by closing the dir, which should free all the
** path_lists nodes. If there is no DIR, then it is the arg_file_list.
** So we free them one by one.
*/

void			ls_free_dir(t_ls_dir_list **node)
{
	if (node == 0 || *node == 0)
		return ;
	if ((*node)->info != 0)
	{
		if ((*node)->dirp != 0)
			closedir((*node)->dirp);
		if ((*node)->info->allocated == 1)
			free((*node)->info->pathname);
		free((*node)->info);
		ls_free_path_list(*node);
		free(*node);
		*node = NULL;
	}
	else
		ls_free_path_list(*node);
}
