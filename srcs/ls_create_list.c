/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:36:26 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 16:04:49 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Insertion sort
*/

static	void	ls_insert_node(t_ls_data *data, char *pathname,
							   int (*cmp)(t_ls_list*, t_ls_list*, short))
{
	t_ls_list *node;
	t_ls_list *prev;
	t_ls_list *next;

	if ((node = ls_create_node(pathname)) == 0)
		return ;
	prev = data->list;
	if (prev == 0)
	{
		data->list = node;
		return ;
	}
	if (cmp(node, prev, data->options) > 0)
	{
		node->next = prev;
		data->list = node;
		return ;
	}
	next = prev->next;
	while (next != 0 && cmp(node, next, data->options) == 0)
	{
		prev = next;
		next = next->next;
	}
	node->next = next;
	prev->next = node;
}

/*
** Add element in a sorted list one by one.
*/

static	void	ls_add_node(t_ls_data *data, char *pathname)
{
	int	(*cmp)(t_ls_list*, t_ls_list*, short);

	if (data->options & LS_SORT_MOD_TIME && data->options & LS_ACCESS_TIME)
		cmp = ls_cmp_last_access;
	else if (data->options & LS_SORT_MOD_TIME)
		cmp = ls_cmp_last_mod;
	else if (data->options & LS_NOT_SORTED)
		cmp = ls_no_sort;
	else
		cmp = ls_cmp_alpha;
	ls_insert_node(data, pathname, cmp);
}

/*
** Create a list of file or directory names from the provided pathname list.
** It does so by sorting the provided list accordings to the
** required options.
*/

void			ls_create_list(int len, char **argv, t_ls_data *data)
{
	int	i;
	
	if (data == 0)
		return;
	i = 0;
	while (i < len)
		ls_add_node(data, argv[i++]);
	if (data->options & LS_ARGS_LIST)
		data->options ^= LS_ARGS_LIST;
}
