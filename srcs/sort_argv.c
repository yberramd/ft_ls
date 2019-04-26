/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:04:03 by yberramd          #+#    #+#             */
/*   Updated: 2019/04/26 13:40:10 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
