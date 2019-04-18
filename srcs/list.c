/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:08:52 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/18 10:26:06 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir	*create_list(int attr, t_dir *first, t_dir *prev, DIR *dir)
{
	t_dir			*current;
	struct dirent	*dirent;

	if ((dirent = readdir(dir)))
	{
		if (!(attr & ARG_A) && dirent->d_name[0] == '.')
			return (create_list(attr, first, prev, dir));
		else if (!(current = malloc(sizeof(t_dir))))
			exit(write(2, "ls: error: malloc failed\n", 25));
	}
	if (!dirent)
		return (attr & ARG_R ? prev : first);
	current->d_name = ft_strdup(dirent->d_name);
	current->file_info = NULL;
	current->next = NULL;
	if (attr & ARG_R && prev)
		current->next = prev;
	else if (prev)
		prev->next = current;
	else
		first = current;
	return (create_list(attr, first, current, dir));
}

int		stat_my_list(const char *path, t_dir *list)
{
	int		i;
	char	*newpath;
	char	*tmp;

	while (list)
	{
		if (!(list->file_info = malloc(sizeof(struct stat))))
			exit(write(2, "ls: error: malloc failed\n", 25));
		tmp = ft_strjoin(path, "/");
		newpath = ft_strjoin(tmp, list->d_name);
		ft_strdel(&tmp);
		i = lstat(newpath, list->file_info);
		ft_strdel(&newpath);
		list = list->next;
	}
	return (!i);
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
