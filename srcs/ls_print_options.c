/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:25:18 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 11:37:33 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

/*
** DEBUG function: prints the options in a human readable fashion
*/

void	ls_print_options(short options)
{
	ft_printf("\n=========Printing options========\nLong Format:\t\t\t%c\n",
		(options & LS_LONG_FORMAT ? 'x' : ' '));
	ft_printf("Recursive search:\t\t%c\n",
		(options & LS_RECURSIVE ? 'x' : ' '));
	ft_printf("Show hidden:\t\t\t%c\n", (options & LS_SHOW_HIDDEN ? 'x' : ' '));
	ft_printf("Reverse order:\t\t\t%c\n",
		(options & LS_REVERSE ? 'x' : ' '));
	ft_printf("Sort by modified time:\t\t%c\n",
		(options & LS_SORT_MOD_TIME ? 'x' : ' '));
	ft_printf("Access time:\t\t\t%c\n",
		(options & LS_ACCESS_TIME ? 'x' : ' '));
	ft_printf("Not sorted:\t\t\t%c\n", (options & LS_NOT_SORTED ? 'x' : ' '));
	ft_printf("Don't show owner:\t\t%c\n",
		(options & LS_NO_OWNER ? 'x' : ' '));
	ft_printf("Treat directories as files:\t%c\n",
		(options & LS_DIR_AS_FILE ? 'x' : ' '));
	ft_printf("Color:\t\t\t\t%c\n=================================\n\n",
		(options & LS_COLOR ? 'x' : ' '));
}
