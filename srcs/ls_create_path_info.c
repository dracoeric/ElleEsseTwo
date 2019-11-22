/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_create_path_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 10:57:36 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 12:34:33 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

t_ls_path_info	*ls_create_path_info(char *pathname)
{
	t_ls_path_info	*info;

	if (!(info = (t_ls_path_info *)malloc(sizeof(t_ls_path_info))))
	{
		perror("ft_ls");
		return (0);
	}
	info->pathname = pathname;
	if ((stat(pathname, &(info->stat))) != 0)
	{
		ft_dprintf(2, "ls: %s: %s\n", pathname, strerror(errno));
		return (0);
	}
	return (info);
}
