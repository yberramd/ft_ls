/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:51:34 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/17 15:44:26 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "../libft/libft.h"

char					*file_mode(char *str, int st_mode)
{
	str[0] = (st_mode & S_IFDIR) == S_IFDIR ? 'd' : '-';
	str[0] = (st_mode & S_IFLNK) == S_IFLNK ? 'l' : str[0];
	str[1] = st_mode & S_IRUSR ? 'r' : '-';
	str[2] = st_mode & S_IWUSR ? 'w' : '-';
	str[3] = st_mode & S_IXUSR ? 'x' : '-';
	str[4] = st_mode & S_IRGRP ? 'r' : '-';
	str[5] = st_mode & S_IWGRP ? 'w' : '-';
	str[6] = st_mode & S_IXGRP ? 'x' : '-';
	str[7] = st_mode & S_IROTH ? 'r' : '-';
	str[8] = st_mode & S_IWOTH ? 'w' : '-';
	str[9] = st_mode & S_IXOTH ? 'x' : '-';
	str[9] = st_mode & S_ISVTX ? 't' : str[9];
	return (str);
}

int		error(int i, const char *c)
{
	char *d;

	write(2, "ls: ", 4);
	if (!i)
		write(2, "failed malloc", 14);
	else if (i == 1)
	{
		write(2, "illegal option -- ", 19);
		write(2, c, 1);
		write(2, "\nusage: ls [-Ralrt] [file ...]\n", 31);
	}
	d = strrchr(c, '/');
	if (d && *(d + 1))
		c = d + 1;
	if (i > 1)
		while (*c)
			write(2, c++, 1);
	if (i == 2) 
		write(2, ": No such file or directory\n", 28);
	if (i == 3) 
		write(2, ": Permission denied\n", 20);
	return(0);
}

int						print_info(const char *path, int attr, time_t t)
{
	struct stat	file_info;
	char		modes[11];

	ft_strcpy(modes, "----------");
	if (lstat(path, &file_info))
		return (error(2, path));
	if (file_info.st_mode & S_IFDIR)
		return (error(3, path));
	if (attr & ARG_L)
	{
		ft_printf("%.10s", file_mode(modes, file_info.st_mode));
		ft_printf("  %d", file_info.st_nlink);
		ft_printf(" %s", getpwuid(file_info.st_uid)->pw_name);
		ft_printf("  %s", getgrgid(file_info.st_gid)->gr_name);
		ft_printf("  %lld", file_info.st_size);
		if (t - file_info.st_mtimespec.tv_sec < 15724800
				&& t - file_info.st_mtimespec.tv_sec > 0)
			ft_printf(" %.12s ", &ctime(&file_info.st_mtimespec.tv_sec)[4]);
		else
			ft_printf(" %.7s %.4s ", &ctime(&file_info.st_mtimespec.tv_sec)[4],
					&ctime(&file_info.st_mtimespec.tv_sec)[20]);
	}
	ft_printf("%s\n", path);
	return (1);
}

static void				max_info(t_dir *list, t_max *max)
{
	max->total = 0;
	max->links = 0;
	max->prp = 0;
	max->grp = 0;
	max->size = 0;
	while (list)
	{
		max->total += list->file_info->st_blocks;
		max->links = max->links > (int)list->file_info->st_nlink
		? max->links : (int)list->file_info->st_nlink;
		if (getpwuid(list->file_info->st_uid) != NULL)
			max->prp =
			max->prp > ft_strlen(getpwuid(list->file_info->st_uid)->pw_name)
			? max->prp : ft_strlen(getpwuid(list->file_info->st_uid)->pw_name);
		else
			max->prp = max->prp > prp_length(list->file_info->st_uid)
			? max->prp : prp_length(list->file_info->st_uid);
		max->grp =
		max->grp > ft_strlen(getgrgid(list->file_info->st_gid)->gr_name)
		? max->grp : ft_strlen(getgrgid(list->file_info->st_gid)->gr_name);
		max->size = max->size > list->file_info->st_size
		? max->size : list->file_info->st_size;
		list = list->next;
	}
}

static void				ft_arg_l(t_dir *list, time_t t, t_max max, char *modes, const char *path)
{
	char	buffer[PATH_MAX + 1];
	size_t	bufsize;

	ft_printf("%.10s", file_mode(modes, list->file_info->st_mode));
	space(ft_index(max.links), ft_index(list->file_info->st_nlink));
	ft_printf("  %d", list->file_info->st_nlink);
	if (getpwuid(list->file_info->st_uid) == NULL)
	{
		ft_printf(" %ld", (long)list->file_info->st_uid);
		space(max.prp, prp_length(list->file_info->st_uid));
	}
	else
	{
		ft_printf(" %s", getpwuid(list->file_info->st_uid)->pw_name);
		space(max.prp, ft_strlen(getpwuid(list->file_info->st_uid)->pw_name));
	}
	ft_printf("  %s", getgrgid(list->file_info->st_gid)->gr_name);
	space(max.grp, ft_strlen(getgrgid(list->file_info->st_gid)->gr_name));
	space(ft_index(max.size), ft_index(list->file_info->st_size));
	ft_printf("  %lld", list->file_info->st_size);
	if (t - list->file_info->st_mtimespec.tv_sec < 15724800
			&& t - list->file_info->st_mtimespec.tv_sec > 0)
		ft_printf(" %.12s ", &ctime(&list->file_info->st_mtimespec.tv_sec)[4]);
	else
		ft_printf(" %.7s %.4s ", &ctime(&list->file_info->st_mtimespec.tv_sec)[4],
				&ctime(&list->file_info->st_mtimespec.tv_sec)[20]);
	if ((bufsize = readlink(ft_strjoin(ft_strjoin(path, "/"), list->d_name), buffer, PATH_MAX)) != (size_t)-1 )//LEAKS IL FAUT UN STRJOINFREE
	{
		ft_printf("%s", list->d_name);
		buffer[bufsize] = '\0';
		ft_printf(" -> %s\n", buffer);
	}
	else
		ft_printf("%s\n", list->d_name);
}

int						print_list(const char *path, int attr, t_dir *list, time_t t)
{
	t_max	max;
	char	modes[11];

	ft_strcpy(modes, "----------");
	if (attr & ARG_L)
	{
		max_info(list, &max);
		if (list)
			ft_printf("total %lld\n", max.total);
		while (list)
		{
			ft_arg_l(list, t, max, modes, path);
			list = list->next;
		}
	}
	else
		while (list)
		{
			ft_printf("%s\n", list->d_name);
			list = list->next;
		}
	return (1);
}
