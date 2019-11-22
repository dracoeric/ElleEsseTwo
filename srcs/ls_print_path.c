/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:05:19 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 15:16:48 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** print the first t_ls_path_list element of list following the format
** defined in options. Then free the first element, placing the second
** element in the first position (pop).
** if `print_folder_name` is 1, then prints the directory's name before the
** file list.
** e.g:
** toto:
** file1 file2
*/

void		ls_print_path(t_ls_dir_list *list, short options,
				char *print_folder_name)
{
	if (list == 0 || options == 0 || print_folder_name == 0)
		return ;
}
