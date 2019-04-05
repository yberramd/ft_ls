/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:25 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/05 15:16:32 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "../libft/libft.h"

t_dir *create_list(int attr, t_dir *first, t_dir *previous, DIR *dir)
{
	t_dir *current;
	struct dirent *dirent;

	if ((dirent = readdir(dir)))
	   if (!(current = malloc(sizeof(t_dir))))
		exit(printf("Failed Malloc") * 0 - 1);
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



void show_list(t_dir *list) //DEBUG.
{
	printf("%s\n", list->d_name);
	while ((list = list->next))
		printf("%s\n", list->d_name);
	printf("\033[0m");
}

void stat_my_list(const char *path, t_dir *list) //Requires libft
{
	while (list)
	{
		(void)path;
		char *newpath;
		list->file_info = malloc(sizeof(struct stat));
		newpath = ft_strjoin(path, list->d_name);
		stat(list->d_name, list->file_info);
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
	list = create_list(attr, NULL, NULL, dir);
	closedir(dir);
	stat_my_list(path, list);
	while (sort(attr, list))
		(void)list;
	printf("\033[0;32m");
	//show_list(list);
	print_info_list(path, attr, list);
	printf("\033[0m");
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
