/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:25 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/16 18:54:12 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "../libft/libft.h"

t_dir	*create_list(int attr, t_dir *first, t_dir *previous, DIR *dir)
{
	t_dir			*current;
	struct dirent	*dirent;

	if ((dirent = readdir(dir)))
	{
		if (!(attr & ARG_a) && dirent->d_name[0] == '.')
			return (create_list(attr, first, previous, dir));
		else if (!(current = malloc(sizeof(t_dir))))
			exit(printf("ls: error: Can't allocate memory\n") * 0 - 1);
	}
	if (!dirent)
		return (attr & ARG_r ? previous : first);
	current->d_name = strdup(dirent->d_name);
	current->file_info = NULL;
	current->next = NULL;
	if (attr & ARG_r && previous)
		current->next = previous;
	else if (previous)
		previous->next = current;
	else
		first = current;
	return (create_list(attr, first, current, dir));
}

int			stat_my_list(const char *path, t_dir *list)
{
	int		i;
	char	*newpath;
	char	*tmp;

	while (list)
	{
		list->file_info = malloc(sizeof(struct stat));
		tmp = ft_strjoin(path, "/");
		newpath = ft_strjoin(tmp, list->d_name);
		ft_strdel(&tmp);
		i = lstat(newpath, list->file_info);
		ft_strdel(&newpath);
		list = list->next;
	}
	return(!i);
}

void	free_my_list(t_dir *list)
{
	t_dir	*next;
	while (list)
	{
		next = list->next;
		if (list->file_info)
			free(list->file_info);
		ft_strdel(&list->d_name);
		free(list);
		list = next;
	}
}

int		ls(int attr, const char *path, time_t t)
{
	DIR		*dir;
	t_dir	*list;
	t_dir	*first;
	char	*next_dir;
	char	*str;

	if (!(dir = opendir(path)))
		return (print_info(path, attr, t));
	list = create_list(attr, NULL, NULL, dir);
	closedir(dir);
	if (!stat_my_list(path, list))
		return(0);
	if (list)
		while (sort(attr, list))
			(void)list;
	print_info_list(path, attr, list, t);
	first = list;
	while (list && attr & ARG_R)
	{
		if (list->file_info->st_mode & S_IFDIR
			&& (!(attr & ARG_a) || 
			(ft_strcmp(list->d_name, ".")
			&& ft_strcmp(list->d_name, ".."))))
		{
			if (path[0] == '/' && !path[1])
				str = ft_strdup(path);
			else
				str = ft_strjoin(path, "/");
			next_dir = ft_strjoin(str, list->d_name);
			printf("\n%s:\n", next_dir);
			ft_strdel(&str);
			ls(attr, next_dir, t);
			ft_strdel(&next_dir);
		}
		list = list->next;
	}
	free_my_list(first);
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		args;
	time_t	t;

	i = 0;
	args = 0;
	time(&t);
	while (++i < argc && argv[i][0] == '-' && argv[i][1] != '-' && !(j = 0))
		while (argv[i][++j])
		{
			if (!ARGS(argv[i][j]))
				exit(printf("ls: illegal option -- %c\nusage: ls [-Ralrt] [file ...]", argv[i][j]) && 0);
			args = args | ARGS(argv[i][j]);
		}
	i += (argv[i] && argv[i][1] == '-');
	j = (i + 1 == argc);
	if (i == argc)
		return (ls(args, ".", t));
	while (i < argc - 1)
	{
		printf("%s:\n", argv[i]);
		ls(args, argv[i++], t);
		printf("\n");
	}
	if (!j)
		printf("%s:\n", argv[i]);
	ls(args, argv[i], t);
}
