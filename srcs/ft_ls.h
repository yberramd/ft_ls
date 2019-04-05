/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:01:05 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/05 12:10:54 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
#define FT_LS
#define ARG_R 1
#define ARG_r 2
#define ARG_t 4
#define ARG_a 8
#define ARG_l 16

#define ARGS(c)	   ((c == 'R') * ARG_R + \
					(c == 'r') * ARG_r + \
					(c == 't') * ARG_t + \
					(c == 'a') * ARG_a + \
					(c == 'l') * ARG_l)


#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>

typedef struct		s_dir
{
	struct dirent	*dirent;
	struct stat		*file_info;
	struct s_dir	*next;
}					t_dir;

//single_elem.c
char	*file_mode(char *str, int st_mode);
int		print_info(const char *path, int attr);
int		print_info_list(const char *path, int attr, t_dir *list);

//sort.c
int		cmp(int attr, t_dir *elem1, t_dir *elem2);
int		sort(int attr, t_dir *list);

//ls.c
<<<<<<< HEAD
t_dir *create_list(int attr, t_dir *first, t_dir *previous, DIR *dir);
void show_list(t_dir *list); //DEBUG.
void stat_my_list(const char *path, t_dir *list); //Requires libft
int ls(int attr, const char *path);
int main(int argc, char **argv); // Pourquoi y a un main dans mon .h ?
t_dir	*create_list(t_dir *first, t_dir *previous, DIR *dir);
void	show_list(t_dir *list); //DEBUG.
void	stat_my_list(const char *path, t_dir *list); //Requires libft
int		ls(int attr, const char *path);
int		main(int argc, char **argv); // Pourquoi y a un main dans mon .h ?
#endif
