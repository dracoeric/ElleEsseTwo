/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_create_dir_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:36:26 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 18:51:50 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Create a list of directories from the provided argument
** It does so by sorting the provided list accordings to the
** required options.
*/

void			ls_create_dir_list(int len, char **argv, t_ls_data *data)
{
	int				i;
	t_ls_dir_list	*dlist;

	if (data == 0)
		return ;
	if ((dlist = ls_create_dir(".")) == 0)
		return ;
	data->list = dlist;
	i = 0;
	while (i < len)
		ls_add_entry(data, argv[i++]);
	if (data->options & LS_ARGS_LIST)
		data->options ^= LS_ARGS_LIST;
}
