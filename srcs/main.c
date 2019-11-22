/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:42:10 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 14:00:04 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_data(t_ls_data *data)
{
	data->dlist = 0;
	data->arg_file_list->info = 0;
	data->arg_file_list->flist = 0;
	data->arg_file_list->max_name_size = 0;
	data->arg_file_list->n_path = 0;
	data->arg_file_list->depth = 0;
}

int		main(int argc, char **argv)
{
	int				args_offset;
	t_ls_data		data[1];
	t_ls_dir_list	arg_files[1];

	args_offset = ls_get_options(argc, argv, &(data->options));
	if (args_offset < 0)
		return (1);
	argv = (argv + args_offset);
	data->arg_file_list = arg_files;
	init_data(data);
	ls_consume_arg_list(argc - args_offset, argv, data);
	ls_print(data);
	return (0);
}
