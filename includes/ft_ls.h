/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:47:18 by erli              #+#    #+#             */
/*   Updated: 2019/11/22 14:00:15 by erli             ###   ########.fr       */
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

# include <sys/stat.h>

/*
** Structures
*/

typedef struct	s_ls_path_info
{
	char		*pathname;
	struct stat	stat;
}				t_ls_path_info;

typedef struct	s_ls_path_list
{
	t_ls_path_info			*info;
	struct s_ls_path_list	*next;
}				t_ls_path_list;

typedef struct	s_ls_dir_list
{
	t_ls_path_info			*info;
	t_ls_path_list			*flist;
	unsigned int			max_name_size;
	int						depth;
	int						n_path;
	struct s_ls_dir_list	*next;
}				t_ls_dir_list;

typedef struct	s_ls_data
{
	t_ls_dir_list	*arg_file_list;
	t_ls_dir_list	*dlist;
	short			options;
}				t_ls_data;

/*
** Core functions
*/
void			ls_consume_arg_list(int len, char **args, t_ls_data *data);
t_ls_path_info	*ls_create_path_info(char *pathname);
t_ls_path_list	*ls_create_path(t_ls_path_info *info);
t_ls_dir_list	*ls_create_dir(t_ls_path_info *info, int depth);
void			ls_add_path(t_ls_dir_list *list, t_ls_path_list *node,
							int (*cmp)(t_ls_path_info*, t_ls_path_info*, short),
					short options);
void			ls_add_dir(t_ls_dir_list **dlist, t_ls_dir_list *node,
					int (*cmp)(t_ls_path_info*, t_ls_path_info*, short),
					short options);
int				ls_get_options(int argc, char **argv, short *options);
void			ls_print(t_ls_data *data);

/*
** Utility functions
*/
int				ls_cmp_alpha(t_ls_path_info *a, t_ls_path_info *b,
					short options);
int				ls_cmp_last_access(t_ls_path_info *a, t_ls_path_info *b,
					short options);
int				ls_cmp_last_mod(t_ls_path_info *a, t_ls_path_info *b,
					short options);
int				ls_no_sort(t_ls_path_info *a, t_ls_path_info *b, short options);
void			ls_usage(void);

/*
** Debuf functions
*/
void			ls_print_options(short options);
void			ls_print_data(t_ls_data *data);

/*
** POC functions
*/
int				ls_get_terminal_width(void);

#endif
