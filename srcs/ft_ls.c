/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:25 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/04 15:58:23 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ARG_R 1
#define ARG_r 2
#define ARG_t 4
#define ARG_a 8
#define ARG_l 16

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

/*Objectif actuel : creer une liste chainee pour pouvoir aficher les fichiers dans n'importe quel sens.*/

int add_args(char c)
{
	/*ls actuel ne gere pas les arguments incorrects*/
	return( (c == 'R') * ARG_R + 
			(c == 'r') * ARG_r +
			(c == 't') * ARG_t +
			(c == 'a') * ARG_a +
			(c == 'l') * ARG_l);
}

char	*file_mode(char *str, int st_mode)
{
	str[0] = st_mode & S_IFDIR ? 'd' : '-';
	str[1] = st_mode & S_IRUSR ? 'r' : '-';
	str[2] = st_mode & S_IWUSR ? 'w' : '-';
	str[3] = st_mode & S_IXUSR ? 'x' : '-';
	str[4] = st_mode & S_IRGRP ? 'r' : '-';
	str[5] = st_mode & S_IWGRP ? 'w' : '-';
	str[6] = st_mode & S_IXGRP ? 'x' : '-';
	str[7] = st_mode & S_IROTH ? 'r' : '-';
	str[8] = st_mode & S_IWOTH ? 'w' : '-';
	str[9] = st_mode & S_IXOTH ? 'x' : '-';
	return (str);
}

int	print_info(const char *path, int attr)
{
	struct stat file_info;
	char modes[10] = "----------";

	if (stat(path, &file_info))
		return(printf("ls: %s: No such file or directory\n", path) & 0);
	if (attr & ARG_l)
	{
		printf("%.10s", file_mode(modes, file_info.st_mode));//Modes
		printf("  %d", file_info.st_nlink);//Nombre de liens
		printf(" %s", getpwuid(file_info.st_uid)->pw_name);//propriétaire
		printf("  %s", getgrgid(file_info.st_gid)->gr_name);//Groupe
		printf("  %lld", file_info.st_size);//Taille
		printf(" %.12s ", &ctime(&file_info.st_mtimespec.tv_sec)[4]);//Date de la dernière modification
	}
	printf("%s\n", path);//Nom
	//	printf("Type: \n");
	return (1);
}

t_dir *create_list(t_dir *first, t_dir *previous, DIR *dir)
{
	t_dir *current;
	struct dirent *dirent;

	if ((dirent = readdir(dir)))
	   if (!(current = malloc(sizeof(t_dir))))
		exit(printf("Failed Malloc") * 0 - 1);
	if (!dirent)
		return(first);
	current->dirent = dirent;
	current->file_info = NULL;
	if (previous)
		previous->next = current;
	else
		first = current;
	return(create_list(first, current, dir));
}

int cmp (int attr, const char *path, t_dir *elem1, t_dir *elem2)
{
	int rtn;
	rtn = 0;
	if (attr & ARG_t)
	{
		rtn = elem1->file_info->st_mtimespec.tv_sec <=
		   	elem2->file_info->st_mtimespec.tv_sec;
	}
	else
	{
		while (elem1->dirent->d_name[rtn] == elem2->dirent->d_name[rtn])
			++rtn;
		rtn = elem1->dirent->d_name[rtn] > elem2->dirent->d_name[rtn];
	}
	if (attr & ARG_r)
		return (!rtn);
	return (rtn);
}

int sort(const char *path, int attr, t_dir *list)
{
	struct dirent *tmp;
	int witness = 0;
	while (list->next)
	{
		if (cmp(attr, path, list, list->next))
		{
			tmp = list->dirent;
			list->dirent = list->next->dirent;
			list->next->dirent = tmp;
			witness = 1;
		}
		list = list->next;
	}
	return(witness);
}

void show_list(t_dir *list) //DEBUG.
{
	printf("%s\n", list->dirent->d_name);
	while ((list = list->next))
		printf("%s\n", list->dirent->d_name);
	printf("\033[0m");
}

void stat_my_list(char *path, t_dir *list) //Requires libft
{
	while (list)
	{
		char *newpath;
		list->file_info = malloc(sizeof(struct stat));
		newpath = ft_strjoin(path, list->dirent->d_name);
		path(newpath, list->file_info);
		free(newpath);
		list = list->next;
	}
}

int ls(int attr, const char *path)
{
	DIR *dir;
	t_dir *list;

	(void)attr;
	if (!(dir = opendir(path)))
		return(print_info(path, attr));
	list = create_list(NULL, NULL, dir);
	closedir(dir);
	printf("\033[0;33m");
	show_list(list);
	while (sort(path, attr, list))
		(void)list;
	printf("\033[0;32m");
	show_list(list);
	return (0);
}


int main(int argc, char **argv)
{
	int i;
	int j;
	int args;

	i = 0;
	args = 0;
	while (++i < argc && argv[i][0] == '-' && !(j = 0))
		while(argv[i][++j])
			args = args | add_args(argv[i][j]);
	if (i == argc)
		return (ls(args, "."));
	while (i < argc)
		ls(args, argv[i++]);
}
