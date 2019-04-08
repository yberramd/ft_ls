/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:25 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/08 11:22:20 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "../libft/libft.h"


//ls -l "total nb" [CHECK]
//-R [CHECK]
//recherche liens symboliques, lstat et pourquoi ./ft_ls -l /etc segfault [CHECK]
//gestion d'erreurs, debug
//ft_ls ne gere pas les arguments invalides (exemple ./ft_ls -x)
//ft_ls ne gere pas les path invalides (exemple ./ft_ls )

t_dir *create_list(int attr, t_dir *first, t_dir *previous, DIR *dir)
{
	t_dir *current;
	struct dirent *dirent;

	if ((dirent = readdir(dir)))
	{
		if (!(attr & ARG_a) && dirent->d_name[0] == '.')
			return(create_list(attr, first, previous, dir));
		else if (!(current = malloc(sizeof(t_dir))))
			exit(printf("ls: error: Can't allocate memory\n") * 0 - 1);
	}
	if (!dirent)
		return(attr & ARG_r ? previous : first);
	current->d_name = strdup(dirent->d_name);
	current->file_info = NULL;
	current->next = NULL;
	if (attr & ARG_r && previous)
		current->next = previous;
	else if (previous)
		previous->next = current;
	else
		first = current;
	return(create_list(attr, first, current, dir));
}

void stat_my_list(const char *path, t_dir *list) //
{
	char *newpath;

	while (list)
	{
		list->file_info = malloc(sizeof(struct stat));
		newpath = ft_strjoin(path, "/");
		newpath = ft_strjoin(newpath, list->d_name); // NEWPATH LEAK ICI CONNARD
		stat(newpath, list->file_info);
		free(newpath);
		list = list->next;
	}
}

int ls(int attr, const char *path)
{
	DIR		*dir;
	t_dir	*list;
	char	*next_dir;

	if (!(dir = opendir(path)))
		return(print_info(path, attr));
	list = create_list(attr, NULL, NULL, dir);
	closedir(dir);
	stat_my_list(path, list);
	while (sort(attr, list))
		(void)list;
	print_info_list(attr, list);
	while (list && attr & ARG_R)
	{
		if (list->file_info->st_mode & S_IFDIR)
		{
			next_dir = ft_strjoinfree(path[0] == '/' && !path[1] ? ft_strdup(path) : ft_strjoin(path, "/"), list->d_name);
			printf ("%s:\n", next_dir);
			ls(attr, next_dir);
			ft_strdel(&next_dir);//peut leaks
		}
		list = list->next;
	}
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
			args = args | ARGS(argv[i][j]);
	if (i == argc)
		return (ls(args, "."));
	while (i < argc)
		ls(args, argv[i++]);
}
