/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:49:28 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 16:08:09 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

t_ls_list	*ls_create_node(char *path)
{
	t_ls_list *node;

	if (!(node = (t_ls_list*)malloc(sizeof(t_ls_list))))
		return (ft_msg_ptr(2, "Could not allocade node\n", 0));
	node->pathname = path;
	if ((stat(path, &(node->stat))) != 0)
	{
		ft_dprintf(2, "ls: %s: %s\n", path, strerror(errno));
		return (0);
	}
	node->next = 0;
	return (node);
}
