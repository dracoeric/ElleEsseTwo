/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_create_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:49:28 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 17:19:25 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <stdio.h>

t_ls_dir_list	*ls_create_dir(t_ls_path_info *info, int depth)
{
	t_ls_dir_list *node;

	if (!(node = (t_ls_dir_list*)malloc(sizeof(t_ls_dir_list))))
	{
		perror("ft_ls");
		return (0);
	}
	node->info = info;
	node->flist = 0;
	node->dirp = 0;
	node->max_name_size = 0;
	node->n_path = 0;
	node->depth = depth;
	node->next = 0;
	return (node);
}
