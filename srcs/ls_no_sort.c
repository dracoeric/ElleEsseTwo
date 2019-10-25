/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_no_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:27:21 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 18:52:34 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Folders are smaller than files if LS_ARGS_LIST is on.
** Return 1 if a > b, 0 if not.
*/

int			ls_no_sort(t_ls_entry_list *a, t_ls_entry_list *b,
				short options)
{
	if (a == 0 || b == 0)
		return (0);
	if (options & LS_ARGS_LIST
		&& (a->stat.st_mode & S_IFDIR) ^ (b->stat.st_mode & S_IFDIR))
		return (a->stat.st_mode & S_IFDIR ? 0 : 1);
	return (0);
}
