/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_update_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:11:24 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 18:53:10 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

/*
** Updates the `max_name_size` and `nb_col_entries` field of data when adding
** a node.
*/

void		ls_update_data(t_ls_data *data, t_ls_entry_list *node)
{
	if (((data->options & LS_ARGS_LIST) && (node->stat.st_mode & S_IFREG))
		|| (!(data->options & LS_ARGS_LIST) && (data->options & LS_RECURSIVE)))
	{
		data->list->nb_col_entries += 1;
		if (ft_strlen(node->pathname) > data->list->max_name_size)
			data->list->max_name_size = ft_strlen(node->pathname);
	}
}
