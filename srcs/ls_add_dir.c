/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_add_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:10:50 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 18:19:25 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_add_dir(t_ls_data *data, char *pathname)
{
	t_ls_dir_list	*dir;
	t_ls_dir_list	*cursor;
	int				i;

	if ((dir = ls_create_dir(pathname)) == 0)
		return ;
	if (data->list == 0)
		data->list = dir;
	else
	{
		i = 0;
		cursor = data->list;
		while (cursor->next != 0 && i < data->list->cursor)
			cursor = cursor->next;
		dir->next = cursor->next;
		cursor->next = dir;
		data->list->cursor += 1;
	}
}
