/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:43:28 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 12:28:09 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

/*
** Process the valid flag by modifying the options variable accordingly
*/

static void	ls_process_flag(char flag, short *options)
{
	if (flag == 'l')
		*options |= LS_LONG_FORMAT;
	else if (flag == 'R')
		*options |= LS_RECURSIVE;
	else if (flag == 'a')
		*options |= LS_SHOW_HIDDEN;
	else if (flag == 'r' && !(*options & LS_NOT_SORTED))
		*options |= LS_REVERSE;
	else if (flag == 't' && !(*options & LS_NOT_SORTED))
		*options |= LS_SORT_MOD_TIME;
	else if (flag == 'u')
		*options |= LS_ACCESS_TIME;
	else if (flag == 'f')
	{
		*options |= LS_NOT_SORTED;
		*options &= ((unsigned short)(-1) - LS_REVERSE - LS_SORT_MOD_TIME);
	}
	else if (flag == 'g')
		*options |= (LS_LONG_FORMAT + LS_NO_OWNER);
	else if (flag == 'd')
		*options |= LS_DIR_AS_FILE;
	else if (flag == 'G')
		*options |= LS_COLOR;
}

/*
** Parse arguments one by one and return 1 if the argument is not an option
*/

static int	ls_parse_arg(char *arg, short *options)
{
	int	i;

	i = 1;
	if (arg[0] != '-' || arg[1] == '\0')
		return (1);
	while (ft_char_in_str(arg[i], FLAGS))
		ls_process_flag(arg[i++], options);
	if (arg[i] == '\0')
		return (0);
	else
	{
		ft_dprintf(2, "ls: illegal option -- %c\n", arg[i]);
		ls_usage();
		return (-1);
	}
}

/*
** Set options to the correct value depending on the given argument, and return
** the index of the first non option argument
*/

int			ls_get_options(int argc, char **argv, short *options)
{
	int	i;
	int	ret;

	i = 1;
	*options = 0;
	ret = 0;
	while (i < argc && !ret)
	{
		if (!(ret = ls_parse_arg(argv[i], options)))
			i++;
	}
	if (ret < 0)
		return (ret);
	return (i);
}
