/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:29:49 by erli              #+#    #+#             */
/*   Updated: 2019/10/18 17:35:35 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prints informations for each file in the list of file provided in arguments,
** with the format and depth specified by options (long, recursive, etc)
*/

void		ls_print(int len, char **list, short options)
{
	int	i;

	i = 0;
	if (options != 0)
	{
		while (i < len && list[i] != 0)
			ft_printf("%s\n", list[i++]);
	}
}
