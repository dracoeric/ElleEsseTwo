/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_create_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:49:28 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 12:34:19 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <stdio.h>

t_ls_path_list	*ls_create_path(t_ls_path_info *info)
{
	t_ls_path_list *node;

	if (info == 0)
		return (0);
	if (!(node = (t_ls_path_list*)malloc(sizeof(t_ls_path_list))))
	{
		perror("ft_ls");
		return (0);
	}
	node->info = info;
	node->next = 0;
	return (node);
}
