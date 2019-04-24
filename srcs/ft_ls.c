/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:25 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/24 16:40:52 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursive(int attr, t_dir *list, const char *path, time_t t)
{
	char	*str;
	char	*next_dir;

	while (list)
	{
		if (list->file_info->st_mode & S_IFDIR
			&& (!(attr & ARG_A) ||
			(ft_strcmp(list->d_name, ".")
			&& ft_strcmp(list->d_name, ".."))))
		{
			if (path[0] == '/' && !path[1])
				str = ft_strdup(path);
			else
				str = ft_strjoin(path, "/");
			next_dir = ft_strjoin(str, list->d_name);
			ft_printf("\n%s:\n", next_dir);
			ft_strdel(&str);
			ls(attr, next_dir, t, 0);
			ft_strdel(&next_dir);
		}
		list = list->next;
	}
}

int		ls(int attr, const char *path, time_t t, int f)
{
	DIR		*dir;
	t_dir	*list;
	t_dir	*first;

	if (!(dir = opendir(path)) || ((readlink(path, NULL, 0) != -1) && !f))
		return (print_info(path, attr, t));
	list = create_list(attr, NULL, NULL, dir);
	closedir(dir);
	if (!stat_my_list(path, list))
		return (0);
	if (list)
		while (sort(attr, list))
			(void)list;
	print_list(path, attr, list, t, 0);
	first = list;
	if (attr & ARG_RR)
		recursive(attr, list, path, t);
	free_my_list(first);
	return (2);
}

void	print_multiple_args(int argc, char **argv, int attr, time_t t)
{
	int i;
	int j;
	int h;
	t_dir *list;

	i = 0;
	list = NULL;
	sort_argv(argc, argv, cmpname);
	if (attr & ARG_T)
		sort_argv(argc, argv, cmpt);
	sort_argv(argc, argv, cmperr);
	h = first_file(argc, argv);
	h = h == -1 ? argc : h;
	if (attr & ARG_R)
		swap_argv(argc - h, &argv[h]);
	if (attr & ARG_L)
		sort_argv(argc, argv, cmpdir);
	else
		sort_argv(argc, argv, cmpdirl);
	j = first_folder(argc, argv, attr);
	j = j == -1 ? argc : j;
	while (i < h)
		ls(attr, argv[i++], t, 0);
	if (h != argc)
		list = list_from_args(&argv[i], j - h);
	if (list)
	{
		stat_my_list("", list);
		print_list("", attr, list, t, 1);
	}
	i = j;
	while (i < argc)
	{
		if ((j > 0 || i > j) && h != i)
			ft_printf("\n");
		if (argc > 1)
			ft_printf("%s:\n", argv[i]);
		ls(attr, argv[i++], t, 1);
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		attr;
	time_t	t;

	i = 0;
	attr = 0;
	time(&t);
	params.buff_index = 0;
	while (++i < argc && argv[i][0] == '-' && argv[i][1] != '-' && !(j = 0))
		while (argv[i][++j])
			if (!ARGS(argv[i][j]) || ((attr = attr | ARGS(argv[i][j])) && 0))
				exit(error(1, &argv[i][j]));
	i += (argv[i] && argv[i][1] == '-');
	if ((j = (i + 1 == argc) || 1) && i == argc)
		return (ls(attr, ".", t, 0));
	print_multiple_args(argc - i, &argv[i], attr, t);
}
