/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_add_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:34:02 by erli              #+#    #+#             */
/*   Updated: 2019/10/18 16:46:04 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Write a char in the buffer, if buffer is full, unloads it and bzeros it.
*/

int			pfd_add_char(t_pfd_data *data, char c)
{
	if (data->cursor + 1 > PRINT_B_SIZE && pfd_unload_buf(data) < 0)
		return (-1);
	data->buf[data->cursor++] = c;
	return (1);
}
