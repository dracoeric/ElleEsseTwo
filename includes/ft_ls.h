/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:47:18 by erli              #+#    #+#             */
/*   Updated: 2019/10/25 15:38:30 by erli             ###   ########.fr       */
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
# define LS_ACCESS_TIME (1 << 6)
# define LS_NOT_SORTED (1 << 7)
# define LS_NO_OWNER (1 << 8)
# define LS_DIR_AS_FILE (1 << 9)
# define LS_COLOR (1 << 10)
# define LS_ARGS_LIST (1 << 11)

# include <sys/stat.h>

#include <stdio.h>

/*
** Structures
*/
typedef struct	s_ls_list
{
	char				*pathname;
	struct stat			stat;
	struct s_ls_list	*next;
}				t_ls_list;

typedef struct	s_ls_data
{
	t_ls_list	*list;
	short		options;
}				t_ls_data;

/*
** Core functions
*/
void			ls_create_list(int len, char **args, t_ls_data *data);
t_ls_list		*ls_create_node(char *path);
int				ls_get_options(int argc, char **argv, short *options);
void			ls_print(int len, char **list, short options);

/*
** Utility functions
*/
int				ls_cmp_alpha(t_ls_list *a, t_ls_list *b, short options);
int				ls_cmp_last_access(t_ls_list *a, t_ls_list *b, short options);
int				ls_cmp_last_mod(t_ls_list *a, t_ls_list *b, short options);
int				ls_no_sort(t_ls_list *a, t_ls_list *b, short options);
void			ls_usage(void);

/*
** Debuf functions
*/
void			ls_print_options(short options);
void			ls_print_data(t_ls_data* data);

/*
** POC functions
*/
int				ls_get_terminal_width(void);

#endif
