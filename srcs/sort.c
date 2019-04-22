/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:05:26 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/22 14:52:28 by yberramd         ###   ########.fr       */
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


// CEST DE LA MERDE MAIS EN ATTENDANT ON FAIT CA
static void	ascii_argv(int argc, char **argv)
{
	int		i;
	int		a;
	int		j;
	char	*tmp;

	i = 0;
	while (i < argc)
	{
		a = 1;
		while (a < argc - 1)
		{
			j = 0;
			while (argv[a][j] == argv[a + 1][j])
				++j;
			if ((unsigned char)argv[a][j] > (unsigned char)argv[a + 1][j])
			{
				tmp = argv[a + 1];
				argv[a + 1] = argv[a];
				argv[a] = tmp;
			}
			a++;
		}
		i++;
	}
}

static void	dir_argv(int argc, char **argv)
{
	int		i;
	int		a;
	char	*tmp;

	i = 0;
	while (i < argc)
	{
		a = 1;
		while (a < argc - 1)
		{
			if ((!(opendir(argv[a + 1])) || readlink(argv[a + 1], NULL, 0) != -1)
				&& !(!(opendir(argv[a])) || readlink(argv[a], NULL, 0) != -1))//A AMELIORER
			{
				tmp = argv[a + 1];
				argv[a + 1] = argv[a];
				argv[a] = tmp;
			}
			a++;
		}
		i++;
	}
}

int		sort_argv(int argc, char **argv)
{
	char		*tmp;
	struct stat	file_info;
	int			a;
	int			i;
	int			rtn;

	i = 0;
	rtn = -1;
	ascii_argv(argc, argv);
	dir_argv(argc, argv);
	while (i < argc)
	{
		a = 1;
		while (a < argc - 1)
		{
			if (lstat(argv[a + 1], &file_info) && !(lstat(argv[a], &file_info)))//A AMELIORER
			{
				tmp = argv[a + 1];
				argv[a + 1] = argv[a];
				argv[a] = tmp;
			}
			(file_info.st_mode & S_IFDIR) == S_IFDIR ? 0 : (rtn = a);
			a++;
		}
		i++;
	}
	return (rtn);
}
