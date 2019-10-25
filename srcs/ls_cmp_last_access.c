/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cmp_last_access.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:27:21 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 18:51:34 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Compares two nodes. A is greater than B if file A has been accessed after
** file B. Folders a smaller than files if LS_ARGS_LIST is on.
** Return 1 if a > b, 0 if not
*/

int			ls_cmp_last_access(t_ls_entry_list *a, t_ls_entry_list *b,
					short options)
{
	int res;

	if (a == 0 || b == 0)
		return (0);
	if (options & LS_ARGS_LIST
		&& (a->stat.st_mode & S_IFDIR) ^ (b->stat.st_mode & S_IFDIR))
		return (a->stat.st_mode & S_IFDIR ? 0 : 1);
	if (a->stat.st_atimespec.tv_sec == b->stat.st_atimespec.tv_sec)
		res = (a->stat.st_atimespec.tv_nsec > b->stat.st_atimespec.tv_nsec);
	else
		res = (a->stat.st_atimespec.tv_sec > b->stat.st_atimespec.tv_sec);
	return (options & LS_REVERSE ? !res : res);
}
