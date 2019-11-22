/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cmp_last_mod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:27:21 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 13:35:07 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Compares two nodes. A is greater than B if file A has been modified after
** file B.
** Return 1 if a > b, 0 if not
*/

int			ls_cmp_last_mod(t_ls_path_info *a, t_ls_path_info *b,
				short options)
{
	int	res;

	if (a == 0 || b == 0)
		return (0);
	if (a->stat.st_mtimespec.tv_sec == b->stat.st_mtimespec.tv_sec)
		res = (a->stat.st_mtimespec.tv_nsec > b->stat.st_mtimespec.tv_nsec);
	else
		res = (a->stat.st_mtimespec.tv_sec > b->stat.st_mtimespec.tv_sec);
	return (options & LS_REVERSE ? !res : res);
}
