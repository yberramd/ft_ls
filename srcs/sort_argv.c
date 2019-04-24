/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:04:03 by yberramd          #+#    #+#             */
/*   Updated: 2019/04/24 14:52:36 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		cmpname(char **argv, int a)
{
	int j;

	j = 0;
	while (argv[a][j] == argv[a + 1][j])
		++j;
	if ((unsigned char)argv[a][j] > (unsigned char)argv[a + 1][j])
		return (1);
	return (0);
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
	return (a);
}

int		cmpdirl(char **argv, int a)
{
	DIR *i;
	DIR *j;

	i = opendir(argv[a]);
	j = opendir(argv[a + 1]);
	if (!j && i)
		a = 1;
	else
		a = 0;
	if (i)
		closedir(i);
	if (j)
		closedir(j);
	return (a);
}

int		cmperr(char **argv, int a)
{
	struct stat file_info;

	if (lstat(argv[a + 1], &file_info) && !(lstat(argv[a], &file_info)))
		return (1);
	return (0);
}

int		cmpt(char **argv, int a)
{
	struct stat file_info;
	struct stat file_info2;

	if (!lstat(argv[a + 1], &file_info2) && !lstat(argv[a], &file_info)
			&& (file_info.st_mtimespec.tv_sec < file_info2.st_mtimespec.tv_sec))
		return (1);
	return (0);
}

int		sort_argv(int argc, char **argv, int f(char **argv, int a))
{
	char		*tmp;
	int			a;
	int			i;

	i = 0;
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
	return (0);
}

int		first_file(int argc, char **argv)
{
	struct stat	file_info;
	int			a;

	a = 0;
	while (a < argc)
	{
		if (!lstat(argv[a], &file_info))
			return (a);
		a++;
	}
	return (-1);
}

int		first_folder(int argc, char **argv, int attr)
{
	struct stat	file_info;
	int			a;

	a = 0;
	file_info.st_mode = 0;
	while (a < argc)
	{
		if (attr & ARG_L)
			lstat(argv[a], &file_info);
		else
			stat(argv[a], &file_info);
		if ((file_info.st_mode & S_IFDIR) == S_IFDIR)
			return (a);
		a++;
	}
	return (-1);
}
