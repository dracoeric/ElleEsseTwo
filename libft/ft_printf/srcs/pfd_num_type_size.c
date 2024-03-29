/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_num_type_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:49:59 by erli              #+#    #+#             */
/*   Updated: 2019/10/18 16:49:10 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		pfd_num_type_size(int flags)
{
	if (flags & HH_MOD)
		return (sizeof(char));
	if (flags & H_MOD)
		return (sizeof(short));
	if (flags & L_MOD)
		return (sizeof(long));
	if (flags & LL_MOD)
		return (sizeof(long long));
	return (sizeof(int));
}
