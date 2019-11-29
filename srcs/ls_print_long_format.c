/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_long_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:34:52 by erli              #+#    #+#             */
/*   Updated: 2019/11/29 16:51:24 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

/*
** print info of the element in long format.
*/

void		ls_print_long_format(t_ls_path_list *elem, short options)
{
	if (elem == 0 || options == 0)
		return ;
	ft_printf("%s\n", elem->info->pathname);
}
