/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_process_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:03:39 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 17:02:55 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Process the first t_ls_dir_list element of data by printing its pathname,
** creating new directories (recursive case), then pop if (free it then place
** the second element in its place).
*/

void		ls_process_dir(t_ls_data *data)
{
	t_ls_dir_list	*head;

	if (data == 0 || data->dlist == 0 || ls_populate_dir(data->dlist) == 0)
		return ;
	head = data->dlist;
	if (data->options & LS_RECURSIVE)
		ls_add_rec_dir(&head, data->cmp, data->options);
	ls_print_path(head, data->options, &(data->print_folder_name));
	data->dlist = head->next;
	ls_free_dir(&head);
}
