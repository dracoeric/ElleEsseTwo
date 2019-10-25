/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:42:10 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 17:35:47 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int			args_offset;
	t_ls_data	data[1];

	args_offset = ls_get_options(argc, argv, &(data->options));
	if (args_offset < 0)
		return (1);
	argv = (argv + args_offset);
	data->list = 0;
	ls_create_dir_list(argc - args_offset, argv, data);
	ls_print(data);
	return (0);
}
