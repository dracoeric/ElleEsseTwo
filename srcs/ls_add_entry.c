/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_add_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:38:18 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 18:50:46 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

/*
** Insert the new entry within the first directory element of data's, list of
** entries.
*/

static	void	ls_insert_entry_but_not_as_first_element(t_ls_data *data,
				t_ls_entry_list *node,
				int (*cmp)(t_ls_entry_list*, t_ls_entry_list*, short))
{
	t_ls_entry_list *prev;
	t_ls_entry_list *next;
	t_ls_dir_list	*head;

	head = data->list;
	prev = head->list;
	next = prev->next;
	while (next != 0 && cmp(node, next, data->options) == 0)
	{
		prev = next;
		next = prev->next;
	}
	prev->next = node;
	node->next = next;
	head->nb_col_entries += 1;
	if (ft_strlen(node->pathname) > head->max_name_size)
		head->max_name_size = ft_strlen(node->pathname);
}

/*
** Insert the new entry at the front of the first directory element.
*/

static	void	ls_insert_entry(t_ls_data *data, char *pathname,
					int (*cmp)(t_ls_entry_list*, t_ls_entry_list*, short))
{
	t_ls_entry_list *node;
	t_ls_dir_list	*head;

	if ((node = ls_create_entry(pathname)) == 0)
		return ;
	if (data->list == 0)
		return ;
	head = data->list;
	if (head->list == 0)
	{
		head->list = node;
		head->nb_col_entries += 1;
		head->max_name_size = ft_strlen(pathname);
	}
	else if (cmp(node, head->list, data->options) > 0)
	{
		node->next = head->list;
		head->list = node;
		head->nb_col_entries += 1;
		if (ft_strlen(pathname) > head->max_name_size)
			head->max_name_size = ft_strlen(pathname);
	}
	else
		ls_insert_entry_but_not_as_first_element(data, node, cmp);
}

/*
** Add entries to the first directory list. If LS_ARGS_LIST is on, will
** add directories when the entry is a directory.
*/

void			ls_add_entry(t_ls_data *data, char *pathname)
{
	int			(*cmp)(t_ls_entry_list*, t_ls_entry_list*, short);
	struct stat	st;

	if ((stat(pathname, &st)) != 0)
	{
		ft_dprintf(2, "ls: %s: %s/n", pathname, strerror(errno));
		return ;
	}
	if (st.st_mode & S_IFDIR && data->options & LS_ARGS_LIST)
		return (ls_add_dir(data, pathname));
	if (data->options & LS_SORT_MOD_TIME && data->options & LS_ACCESS_TIME)
		cmp = ls_cmp_last_access;
	else if (data->options & LS_SORT_MOD_TIME)
		cmp = ls_cmp_last_mod;
	else if (data->options & LS_NOT_SORTED)
		cmp = ls_no_sort;
	else
		cmp = ls_cmp_alpha;
	ls_insert_entry(data, pathname, cmp);
}
