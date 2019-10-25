/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_terminal_width.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:07:13 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 11:08:34 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <unistd.h>

int		ls_get_terminal_width(void)
{
	struct winsize ws;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	return (ws.ws_col);
}
