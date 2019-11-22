/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_add_rec_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:48:27 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 17:03:26 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Parse all the pathname element within a directory, and add all pathname that
** are directories to the list of directories, with an increased depth
*/

void	ls_add_rec_dir(t_ls_dir_list **list,
			int (*cmp)(t_ls_path_info*, t_ls_path_info*, short),
			short options)
{
	t_ls_dir_list	*head;
	t_ls_path_list	*path;
	t_ls_dir_list	*node;

	if (list == 0 || *list == 0)
		return ;
	head = *list;
	path = head->flist;
	while (path != 0)
	{
		if (path->info->stat.st_mode & S_IFDIR
			&& (node = ls_create_dir(path->info, head->depth + 1)) != 0)
			ls_add_dir(list, node, cmp, options);
		path = path->next;
	}
}
