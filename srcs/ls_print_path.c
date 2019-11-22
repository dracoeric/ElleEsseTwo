/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:05:19 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 17:56:05 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

 #include "libft.h"

/*
** print all the t_ls_path_list elemet following the format
** defined in options.
** if `print_folder_name` is 0, then prints the directory's name before the
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
