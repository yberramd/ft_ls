/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:01:05 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/17 11:05:35 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define ARG_R 1
# define ARG_r 2
# define ARG_t 4
# define ARG_a 8
# define ARG_l 16
# define ARGS(c)	((c == 'R') * ARG_R + \
					(c == 'r') * ARG_r + \
					(c == 't') * ARG_t + \
					(c == 'a') * ARG_a + \
					(c == 'l') * ARG_l)

# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <limits.h>
# include "../ft_printf/includes/ft_printf.h"

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

//single_elem.c
char			*file_mode(char *str, int st_mode);
int				print_info(const char *path, int attr, time_t t);
int				print_info_list(const char *path, int attr, t_dir *list, time_t t);

//sort.c
int				cmp(int attr, t_dir *elem1, t_dir *elem2);
int				sort(int attr, t_dir *list);

//ls.c
t_dir			*create_list(int attr, t_dir *first, t_dir *previous, DIR *dir);
void			show_list(t_dir *list); //DEBUG.
int				stat_my_list(const char *path, t_dir *list); //Requires libft
int				ls(int attr, const char *path, time_t t);

//additional_functions.c
void			space(long biggest, long lower);
int				ft_index(long nbr);
unsigned long	prp_length(unsigned int nbr);
#endif
