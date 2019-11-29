/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_populate_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:31:19 by erli              #+#    #+#             */
/*   Updated: 2019/11/29 16:45:08 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

/*
** Populate the pathname listof the directories with all the pathname that it
** contains (with readdir)
*/

int			ls_populate_dir(t_ls_dir_list *list,
				int (*cmp)(t_ls_path_info*, t_ls_path_info*, short),
				short options)
{
	struct dirent	*entry;
	t_ls_path_info	*info;
	t_ls_path_list	*node;

	if (list == 0)
		return (1);
	if (!(list->dirp = opendir(list->info->pathname)))
	{
		perror("ft_ls");
		return (1);
	}
	while ((entry = readdir(list->dirp)) != NULL)
	{
		if (!(info = ls_create_path_info(entry->d_name, 0))
			|| !(node = ls_create_path(info)))
			return (1);
		ls_add_path(list, node, cmp, options);
	}
	return (0);
}
