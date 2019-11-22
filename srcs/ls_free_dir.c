/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_free_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:35:45 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 17:29:08 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

#include "libft.h"

void	ls_free_dir(t_ls_dir_list **node)
{
	if (node == 0 || *node == 0)
		return ;
	closedir((*node)->dirp);
	if ((*node)->flist != 0)
		ft_putstr_fd("Closedire did not free directory's entries", 2);
	free((*node)->info->pathname);
	free((*node)->info);
	free(*node);
	*node = NULL;
}
