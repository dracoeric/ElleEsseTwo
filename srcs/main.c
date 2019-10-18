/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:42:10 by erli              #+#    #+#             */
/*   Updated: 2019/10/18 17:40:11 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		main(int argc, char **argv)
{
	short	options;
	int		args_offset;

	args_offset = ls_get_options(argc, argv, &options);
	if (args_offset < 0)
		return (1);
	ls_print_options(options);
	ft_printf("First non option argument start at index %d\n", args_offset);
	argv = (argv + args_offset);
	ls_create_list_from_args(argc - args_offset, argv, options);
	ls_print(argc - args_offset, argv, options);
	return (0);
}
