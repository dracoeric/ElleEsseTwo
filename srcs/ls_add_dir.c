/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_add_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:10:50 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 13:58:54 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Add the directry node to the list (in a sorted manner)
*/

static void	ls_add_dir_node(t_ls_dir_list **list, t_ls_dir_list *node,
				int (*cmp)(t_ls_path_info*, t_ls_path_info*, short),
				short options)
{
	t_ls_dir_list	*prev;
	t_ls_dir_list	*next;

	prev = *list;
	if (prev == 0)
		*list = node;
	else if (cmp(node->info, prev->info, options) == 1)
	{
		*list = node;
		node->next = prev;
	}
	else
	{
		next = prev->next;
		while (next != 0 && next->depth == node->depth
			&& cmp(node->info, next->info, options) == 0)
		{
			prev = next;
			next = next->next;
		}
		prev->next = node;
		node->next = next;
	}
}

/*
** Add the directory pathname to the list if in the same depth. Add it right
** after the list head if the depth is greater (adding child)
*/

void		ls_add_dir(t_ls_dir_list **dlist, t_ls_dir_list *node,
				int (*cmp)(t_ls_path_info*, t_ls_path_info*, short),
				short options)
{
	if (dlist == 0 || node == 0)
		return ;
	if (*dlist == 0)
		*dlist = node;
	else
	{
		if ((*dlist)->depth == node->depth)
			ls_add_dir_node(dlist, node, cmp, options);
		else
			ls_add_dir_node(&((*dlist)->next), node, cmp, options);
	}
}
