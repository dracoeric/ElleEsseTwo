/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:05:19 by erli              #+#    #+#             */
/*   Updated: 2019/11/29 16:56:50 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <unistd.h>

/*
** print all the element of the path list with the right padding according to
** the terminal width.
*/

static void		ls_print_path_padding(t_ls_dir_list *dir, short options)
{
	if (dir == 0 || options)
		return ;
}

static void		ls_print_total_block(t_ls_dir_list *dir)
{
	unsigned int	total;
	t_ls_path_list	*bubble;

	if (dir == 0)
		return ;
	total = 0;
	bubble = dir->flist;
	while (dir->info != 0 && bubble != 0)
	{
		total += (unsigned int)bubble->info->stat.st_blocks;
		bubble = bubble->next;
	}
	if (total != 0)
		ft_printf("total %d\n", (int)dir->info->stat.st_blocks);
}

/*
** print all element of the path list one by one with the long format
*/

static void		ls_print_path_long(t_ls_dir_list *dir, short options)
{
	t_ls_path_list *bubble;

	ls_print_total_block(dir);
	bubble = dir->flist;
	while (bubble != 0)
	{
		if (options & LS_SHOW_HIDDEN
			|| bubble->info->pathname[0] != '.')
			ls_print_long_format(bubble, options);
		bubble = bubble->next;
	}
}

/*
** print all the t_ls_path_list elemet following the format
** defined in options.
** if `print_dir_name` is 1, prints the directory name above the file list.
** e.g:
** toto:
** file1 file2
*/

void			ls_print_path(t_ls_dir_list *list, short options,
					char print_dir_name)
{
	if (list == 0)
		return ;
	if (print_dir_name == 1)
		ft_printf("%s:\n", list->info->pathname);
	if (options & LS_LONG_FORMAT)
		ls_print_path_long(list, options);
	else
		ls_print_path_padding(list, options);
}
