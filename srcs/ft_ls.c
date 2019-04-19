/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:25 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/19 15:02:35 by yberramd         ###   ########.fr       */
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
			ls(attr, next_dir, t);
			ft_strdel(&next_dir);
		}
		list = list->next;
	}
}

int		ls(int attr, const char *path, time_t t)
{
	DIR		*dir;
	t_dir	*list;
	t_dir	*first;

	if (!(dir = opendir(path)) || readlink(path, NULL, 0) != -1)
		return (print_info(path, attr, t));
	ft_printf("%s:\n", path);
	list = create_list(attr, NULL, NULL, dir);
	closedir(dir);
	if (!stat_my_list(path, list))
		return (0);
	if (list)
		while (sort(attr, list))
			(void)list;
	print_list(path, attr, list, t);
	first = list;
	if (attr & ARG_RR)
		recursive(attr, list, path, t);
	free_my_list(first);
	return (2);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		args;
	char	**av;
	time_t	t;

	i = 0;
	args = 0;
	time(&t);
	params.buff_index = 0;
	while (++i < argc && argv[i][0] == '-' && argv[i][1] != '-' && !(j = 0))
		while (argv[i][++j])
			if (!ARGS(argv[i][j]) || ((args = args | ARGS(argv[i][j])) && 0))
				exit(error(1, &argv[i][j]));
	i += (argv[i] && argv[i][1] == '-');
	if ((j = (i + 1 == argc) || 1) && i == argc)
		return (ls(args, ".", t));
	av = sort_argv(argc, argv);
	while (i < argc - 1)
	{
		if (ls(args, av[i++], t) == 2)
			ft_printf("\n");
		add_char_to_buff('\n');
	}
	j ? (void)j : ft_printf("%s:\n", av[i]);
	ls(args, av[i], t);
}
