/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:05:26 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/23 14:48:18 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	cmp(int attr, t_dir *elem1, t_dir *elem2)
{
	int	i;

	i = 0;
	if (attr & ARG_T && attr & ARG_R)
		return (elem1->file_info->st_mtimespec.tv_sec
				> elem2->file_info->st_mtimespec.tv_sec);
	else if (attr & ARG_T)
		return (elem1->file_info->st_mtimespec.tv_sec
				< elem2->file_info->st_mtimespec.tv_sec);
	else
		while (elem1->d_name[i] == elem2->d_name[i])
			++i;
	i = (unsigned char)elem1->d_name[i] > (unsigned char)elem2->d_name[i];
	if (attr & ARG_R)
		return (!i);
	return (i);
}

int	sort(int attr, t_dir *list)
{
	void	*tmp;
	int		witness;

	witness = 0;
	while (list->next)
	{
		if (cmp(attr, list, list->next))
		{
			tmp = list->d_name;
			list->d_name = list->next->d_name;
			list->next->d_name = tmp;
			tmp = list->file_info;
			list->file_info = list->next->file_info;
			list->next->file_info = tmp;
			witness = 1;
		}
		list = list->next;
	}
	return (witness);
}

int		cmpname(char **argv, int a)
{
	int j;

	j = 0;
	while (argv[a][j] == argv[a + 1][j])
		++j;
	if ((unsigned char)argv[a][j] > (unsigned char)argv[a + 1][j])
		return(1);
	return(0);
}

int		cmpdir(char **argv, int a)
{
	DIR *i;
	DIR *j;

	i = opendir(argv[a]);
	j = opendir(argv[a + 1]);
	if ((!j || readlink(argv[a + 1], NULL, 0) != -1)
		&& !(!i || readlink(argv[a], NULL, 0) != -1))
		a = 1;
	else 
		a = 0;
	if (i)
		closedir(i);
	if (j)
		closedir(j);
	return(a);
}

int		cmperr(char **argv, int a)
{
	struct stat file_info;

	if (lstat(argv[a + 1], &file_info) && !(lstat(argv[a], &file_info)))
		return(1);
	return(0);
}

int		sort_argv(int argc, char **argv, int f(char **argv, int a))
{
	char		*tmp;
	int			a;
	int			i;
	int			rtn;

	i = 0;
	rtn = -1;
	while (i < argc)
	{
		a = 0;
		while (a < argc - 1)
		{
			if (f(argv, a))
			{
				tmp = argv[a + 1];
				argv[a + 1] = argv[a];
				argv[a] = tmp;
			}
			a++;
		}
		i++;
	}
	return (rtn);
}

int first_folder(int argc, char **argv)
{
	struct stat file_info;
	int a;

	a = 0;
	file_info.st_mode = 0;
	while (a < argc)
	{
		lstat(argv[a], &file_info);
		if ((file_info.st_mode & S_IFDIR) == S_IFDIR)
			return (a);
		a++;
	}
	return (-1); 
}
