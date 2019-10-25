/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cmp_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:27:21 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 18:50:55 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

/*
** Compares two nodes. A is greater than B if file A is before file B in
** ASCII order. Folders a smaller than files if LS_ARGS_LIST is on.
** Return 1 if a > b, 0 if not
*/

int			ls_cmp_alpha(t_ls_entry_list *a, t_ls_entry_list *b,
				short options)
{
	if (a == 0 || b == 0)
		return (0);
	if (options & LS_ARGS_LIST
		&& (a->stat.st_mode & S_IFDIR) ^ (b->stat.st_mode & S_IFDIR))
		return (a->stat.st_mode & S_IFDIR ? 0 : 1);
	if (ft_strcmp(a->pathname, b->pathname) < 0)
		return ((options & LS_REVERSE ? 0 : 1));
	return ((options & LS_REVERSE ? 1 : 0));
}
