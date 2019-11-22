/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_process_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:03:39 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 17:49:02 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void	ls_pop_head(t_ls_dir_list **list)
{
	t_ls_dir_list	*head;

	if (list == 0 || *list == 0)
		return ;
	head = *list;
	*list = head->next;
	ls_free_dir(&head);
}

/*
** Process the first t_ls_dir_list element of data by printing its pathname,
** creating new directories (recursive case), then pop if (free it then place
** the second element in its place).
*/

void		ls_process_dir(t_ls_data *data)
{
	if (data == 0 || data->dlist == 0)
		return ;
	if (!data->print_folder_name)
		ft_printf("%s:\n", data->dlist->info->pathname);
	if (ls_populate_dir(data->dlist, data->cmp, data->options) != 0)
	{
		ls_pop_head(&(data->dlist));
		return ;
	}
	if (data->options & LS_RECURSIVE)
		ls_add_rec_dir(&(data->dlist), data->cmp, data->options);
	ls_print_path(data->dlist, data->options, &(data->print_folder_name));
	ls_pop_head(&(data->dlist));
}
