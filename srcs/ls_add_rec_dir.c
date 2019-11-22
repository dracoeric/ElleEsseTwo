/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_add_rec_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:48:27 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 17:18:18 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

/*
** Parse all the pathname element within a directory, and add all pathname that
** are directories to the list of directories, with an increased depth
*/
static	t_ls_path_info	*ls_clone_info(t_ls_path_info* info)
{
	t_ls_path_info	*clone;
	char			*clone_pathname;

	if (!(clone_pathname = ft_strdup(info->pathname)))
		return (ft_msg_ptr(2, "ft_strdup failled to allocate memory", 0));
	if (!(clone = ls_create_path_info(clone_pathname)))
		return (0);
	return (clone);
}

void					ls_add_rec_dir(t_ls_dir_list **list,
			int (*cmp)(t_ls_path_info*, t_ls_path_info*, short),
			short options)
{
	t_ls_dir_list	*head;
	t_ls_path_list	*path;
	t_ls_dir_list	*node;
	t_ls_path_info	*info;

	if (list == 0 || *list == 0)
		return ;
	head = *list;
	path = head->flist;
	while (path != 0)
	{
		if (!(info = ls_clone_info(path->info))
			&& path->info->stat.st_mode & S_IFDIR
			&& (node = ls_create_dir(path->info, head->depth + 1)) != 0)
			ls_add_dir(list, node, cmp, options);
		path = path->next;
	}
}
