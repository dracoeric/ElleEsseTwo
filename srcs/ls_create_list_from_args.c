/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_create_list_from_args.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:36:26 by erli              #+#    #+#             */
/*   Updated: 2019/10/18 17:41:28 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a list of file or directory names from the provided command line
** arguments. It does so by sorting the provided list accordings to the
** required options and removing non accessible files or directories.
** Every move is done in place.
*/

void		ls_create_list_from_args(int len, char **list, short options)
{
	if (len != 0 && list != 0 && options != 0)
		return ;
}
