/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_add_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:38:18 by erli              #+#    #+#             */
/*   Updated: 2019/11/29 16:45:21 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

/*
** Insert the new path within the directory list paths.
*/

static	void	ls_insert_path_but_not_as_first_element(t_ls_dir_list *dlist,
					t_ls_path_list *node,
					int (*cmp)(t_ls_path_info*, t_ls_path_info*, short),
					short options)
{
	t_ls_path_list	*prev;
	t_ls_path_list	*next;
	unsigned int	len;

	prev = dlist->flist;
	next = prev->next;
	while (next != 0 && cmp(node->info, next->info, options) == 0)
	{
		prev = next;
		next = prev->next;
	}
	prev->next = node;
	node->next = next;
	dlist->n_path += 1;
	len = ft_strlen(node->info->pathname);
	if ((options & LS_SHOW_HIDDEN || node->info->pathname[0] != '.')
		&& len > dlist->max_name_size)
		dlist->max_name_size = len;
}

/*
** Add path to the directory list.
*/

void			ls_add_path(t_ls_dir_list *dlist, t_ls_path_list *node,
					int (*cmp)(t_ls_path_info*, t_ls_path_info*, short),
					short options)
{
	t_ls_path_list	*head;
	unsigned int	len;

	if (dlist == 0 || node == 0)
		return ;
	head = dlist->flist;
	if (head == 0)
	{
		dlist->flist = node;
		dlist->n_path += 1;
		dlist->max_name_size = ft_strlen(node->info->pathname);
	}
	else if (cmp(node->info, head->info, options) == 1)
	{
		node->next = head;
		dlist->flist = node;
		dlist->n_path += 1;
		len = ft_strlen(node->info->pathname);
		if ((options & LS_SHOW_HIDDEN || node->info->pathname[0] != '.')
			&& len > dlist->max_name_size)
			dlist->max_name_size = len;
	}
	else
		ls_insert_path_but_not_as_first_element(dlist, node, cmp, options);
}
