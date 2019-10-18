/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:47:18 by erli              #+#    #+#             */
/*   Updated: 2019/10/18 17:35:42 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# define FLAGS "lRartufgdG"
# define LS_LONG_FORMAT 1
# define LS_RECURSIVE (1 << 1)
# define LS_SHOW_HIDDEN (1 << 2)
# define LS_REVERSE (1 << 3)
# define LS_SORT_MOD_TIME (1 << 4)
# define LS_SORT_ALPHA (1 << 5)
# define LS_ACCESS_TIME (1 << 6)
# define LS_NOT_SORTED (1 << 7)
# define LS_NO_OWNER (1 << 8)
# define LS_DIR_AS_FILE (1 << 9)
# define LS_COLOR (1 << 10)

/*
** Core functions
*/
void		ls_create_list_from_args(int len, char **list, short options);
int			ls_get_options(int argc, char **argv, short *options);
void		ls_print(int len, char **list, short options);

/*
** Utility functions
*/
void		ls_usage(void);

/*
** Debuf functions
*/

void		ls_print_options(short options);

#endif
