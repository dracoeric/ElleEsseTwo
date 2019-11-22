/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_consume_arg_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:36:26 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 16:57:03 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Add the argument pathname to the list of directories, or the list of files
** while sorting the element in the list.
*/

void	ls_consume_arg(t_ls_data *data, char *pathname)
{
	t_ls_path_info		*info;
	t_ls_dir_list		*dir_node;
	t_ls_path_list		*path_node;

	if ((info = ls_create_path_info(pathname)) != 0)
	{
		if (info->stat.st_mode & S_IFDIR)
		{
			if (!(dir_node = ls_create_dir(info, 0)))
				return ;
			ls_add_dir(&(data->dlist), dir_node, data->cmp, data->options);
		}
		else
		{
			if (!(path_node = ls_create_path(info)))
				return ;
			ls_add_path(data->arg_file_list, path_node, data->cmp,
				data->options);
		}
	}
}

/*
** Create a list of directories and the list of files from the provided
** arguments. It does so by sorting the provided list accordings to the
** required options.
*/

void	ls_consume_arg_list(int len, char **argv, t_ls_data *data)
{
	int	i;

	if (data == 0)
		return ;
	i = 0;
	while (i < len)
		ls_consume_arg(data, argv[i++]);
}
