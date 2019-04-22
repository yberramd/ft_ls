/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:01:05 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/22 11:59:55 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"

# define ARG_RR 1
# define ARG_R 2
# define ARG_T 4
# define ARG_A 8
# define ARG_L 16
# define ARGS_S(c)	((c == 'a') * 8 + (c == 'l') * 16)
# define ARGS(c)	((c == 'R') + (c == 'r') * 2 + (c == 't') * 4 + ARGS_S(c))

typedef struct		s_dir
{
	char			*d_name;
	struct stat		*file_info;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_max
{
	int				links;
	unsigned long	prp;
	unsigned long	grp;
	long long		size;
	long long int	total;
}					t_max;

char				*file_mode(char *str, int st_mode);
int					print_info(const char *path, int attr, time_t t);
int					print_list(const char *path, int a, t_dir *list, time_t t);
int					cmp(int attr, t_dir *elem1, t_dir *elem2);
int					sort(int attr, t_dir *list);
t_dir				*create_list(int attr, t_dir *first, t_dir *prev, DIR *dir);
int					stat_my_list(const char *path, t_dir *list);
void				free_my_list(t_dir *list);
int					ls(int attr, const char *path, time_t t);
void				space(long biggest, long lower);
int					ft_index(long nbr);
unsigned long		prp_length(unsigned int nbr);
int					error(int i, const char *c);
void				ft_link(char c, const char *path, const char *name);
int					sort_argv(int argc, char **argv);

#endif
