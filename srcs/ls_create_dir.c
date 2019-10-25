/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_create_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:49:28 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 18:57:28 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

t_ls_dir_list	*ls_create_dir(char *path)
{
	t_ls_dir_list *node;

	if (!(node = (t_ls_dir_list*)malloc(sizeof(t_ls_dir_list))))
	{
		perror("ft_ls");
		exit(EXIT_FAILURE);
	}
	node->pathname = path;
	node->list = 0;
	node->max_name_size = 0;
	node->nb_col_entries = 0;
	node->cursor = 0;
	node->next = 0;
	return (node);
}
