/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_create_entry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:49:28 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 18:52:13 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

t_ls_entry_list	*ls_create_entry(char *path)
{
	t_ls_entry_list *node;

	if (!(node = (t_ls_entry_list*)malloc(sizeof(t_ls_entry_list))))
	{
		perror("ft_ls");
		exit(EXIT_FAILURE);
	}
	node->pathname = path;
	if ((stat(path, &(node->stat))) != 0)
	{
		ft_dprintf(2, "ls: %s: %s\n", path, strerror(errno));
		return (0);
	}
	node->next = 0;
	return (node);
}
