/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:04:10 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 18:49:57 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ls_print_data(t_ls_data *data)
{
	t_ls_dir_list	*dir_bubble;
	t_ls_entry_list	*entry_bubble;

	ft_putstr("\n========== Data ==========\nList:\n");
	dir_bubble = data->list;
	while (dir_bubble != 0)
	{
		ft_printf("%s:\n", dir_bubble->pathname);
		entry_bubble = dir_bubble->list;
		while (entry_bubble != 0)
		{
			ft_printf("%s->", entry_bubble->pathname);
			entry_bubble = entry_bubble->next;
		}
		ft_putstr("0\n\n");
		ft_printf("max_name_size:\t%u\nnb_entries:\t\t%d\n",
			dir_bubble->max_name_size, dir_bubble->nb_col_entries);
		dir_bubble = dir_bubble->next;
	}
	ls_print_options(data->options);
}
