/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:42:10 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 15:19:02 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_print_arg_files(t_ls_dir_list *list, short options,
				char *print_folder_name)
{
	if (list == 0)
		return ;
	while (list->flist != 0)
		ls_print_path(list, options, print_folder_name);
}

static void	ls_init_data(t_ls_data *data)
{
	data->dlist = 0;
	data->print_folder_name = 0;
	data->arg_file_list->info = 0;
	data->arg_file_list->flist = 0;
	data->arg_file_list->max_name_size = 0;
	data->arg_file_list->n_path = 0;
	data->arg_file_list->depth = 0;
}

int			main(int argc, char **argv)
{
	int				args_offset;
	t_ls_data		data[1];
	t_ls_dir_list	arg_files[1];

	data->arg_file_list = arg_files;
	ls_init_data(data);
	args_offset = ls_get_options(argc, argv, &(data->options));
	if (args_offset < 0)
		return (1);
	argv = (argv + args_offset);
	ls_consume_arg_list(argc - args_offset, argv, data);
	ls_print_arg_files(data->arg_file_list, data->options,
		&(data->print_folder_name));
	while (data->dlist != 0)
		ls_process_dir(data);
	return (0);
}
