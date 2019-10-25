/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:04:10 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 15:09:09 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ls_print_data(t_ls_data *data)
{
	t_ls_list *bubble;

	ft_putstr("\n========== Data ==========\nList:\n");
	bubble = data->list;
	while (bubble != 0)
	{
		ft_printf("%s->", bubble->pathname);
		bubble = bubble->next;
	}
	ft_putstr("0\n\n");
	ls_print_options(data->options);
}
