/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:04:10 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 13:58:23 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void	ls_print_arg_data(t_ls_dir_list *list)
{
	t_ls_path_list *bubble;

	if (list == 0)
		ft_putstr("no Argument\n");
	bubble = list->flist;
	ft_putstr("argumentlist:\n");
	while (bubble != 0)
	{
		ft_printf("%s->", bubble->info->pathname);
		bubble = bubble->next;
	}
	ft_putstr("0\n");
	ft_printf("max_name_size:\t%u\nnb_entries:\t%d\n",
		list->max_name_size, list->n_path);
}

void		ls_print_data(t_ls_data *data)
{
	t_ls_dir_list	*dir_bubble;
	t_ls_path_list	*path_bubble;

	ft_putstr("\n========== Data ==========\nList:\n");
	dir_bubble = data->dlist;
	ls_print_arg_data(data->arg_file_list);
	while (dir_bubble != 0)
	{
		ft_printf("\n%s:\n", dir_bubble->info->pathname);
		path_bubble = dir_bubble->flist;
		while (path_bubble != 0)
		{
			ft_printf("%s->", path_bubble->info->pathname);
			path_bubble = path_bubble->next;
		}
		ft_putstr("0\n");
		ft_printf("max_name_size:\t%u\nnb_entries:\t%d\n",
			dir_bubble->max_name_size, dir_bubble->n_path);
		dir_bubble = dir_bubble->next;
	}
	ls_print_options(data->options);
}
