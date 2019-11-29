/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:42:10 by erli              #+#    #+#             */
/*   Updated: 2019/11/29 16:24:30 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
 #include <stdio.h>
static void	ls_print_arg_files(t_ls_dir_list *list, short options)
{
	if (list == 0)
		return ;
	ls_print_path(list, options, 0);
	ls_free_dir(&list);
}

static void	ls_set_cmp(t_ls_data *data)
{
	if (data->options & LS_SORT_MOD_TIME && data->options & LS_ACCESS_TIME)
		data->cmp = ls_cmp_last_access;
	else if (data->options & LS_SORT_MOD_TIME)
		data->cmp = ls_cmp_last_mod;
	else if (data->options & LS_NOT_SORTED)
		data->cmp = ls_no_sort;
	else
		data->cmp = ls_cmp_alpha;
}

static void	ls_init_data(t_ls_data *data)
{
	data->dlist = 0;
	data->print_dir_name = 0;
	data->arg_file_list->info = 0;
	data->arg_file_list->flist = 0;
	data->arg_file_list->max_name_size = 0;
	data->arg_file_list->n_path = 0;
	data->arg_file_list->depth = 0;
}

static void	ls_add_root_dir(t_ls_data *data)
{
	t_ls_path_info	*info;
	t_ls_dir_list	*dir;

	if (!(info = ls_create_path_info(".", 1)))
		return ;
	if (!(dir = ls_create_dir(info, 0)))
		return ;
	dir->next = data->dlist;
	data->dlist = dir;
	data->print_dir_name = 0;
}

int			main(int argc, char **argv)
{
	int				args_offset;
	t_ls_data		data[1];
	t_ls_dir_list	arg_files[1];

	data->arg_file_list = arg_files;
	ls_init_data(data);
	args_offset = ls_get_options(argc, argv, &(data->options));
	ls_set_cmp(data);
	if (args_offset < 0)
		return (1);
	argv = (argv + args_offset);
	ls_consume_arg_list(argc - args_offset, argv, data);
	if (data->arg_file_list == 0 && data->dlist == 0)
		ls_add_root_dir(data);
	ls_print_arg_files(data->arg_file_list, data->options);
	while (data->dlist != 0)
		ls_process_dir(data);
	return (0);
}
