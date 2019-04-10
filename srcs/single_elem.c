/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:51:34 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/10 13:11:15 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "../libft/libft.h"

// etrange : ls -l /Library/Application\ Support/CrashReporter

char		*file_mode(char *str, int st_mode)
{
	str[0] = st_mode & S_IFDIR ? 'd' : '-';
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

int			print_info(const char *path, int attr, time_t t)
{
	struct stat file_info;
	char modes[10] = "----------";

	if (lstat(path, &file_info))
		return(printf("ls: %s: No such file or directory\n", path) & 0);
	if (file_info.st_mode & S_IFDIR)
		return(printf("ls: %s: Permission denied\n", path) & 0);
	if (attr & ARG_l)
	{
		printf("%.10s", file_mode(modes, file_info.st_mode));//Modes
		printf("  %d", file_info.st_nlink);//Nombre de liens
		printf(" %s", getpwuid(file_info.st_uid)->pw_name);//propriétaire
		printf("  %s", getgrgid(file_info.st_gid)->gr_name);//Groupe
		printf("  %lld", file_info.st_size);//Taille
		//printf(" %.12s ", &ctime(&file_info.st_mtimespec.tv_sec)[4]);//Date de la dernière modification
			if (t - file_info.st_mtimespec.tv_sec < 15724800 && t - file_info.st_mtimespec.tv_sec > 0)
				printf(" %.12s ", &ctime(&file_info.st_mtimespec.tv_sec)[4]);//Date de la dernière modification PB: ls -l sur Documents "2018"
			else
				printf(" %.7s %.4s ", &ctime(&file_info.st_mtimespec.tv_sec)[4], &ctime(&file_info.st_mtimespec.tv_sec)[20]);//Date de la dernière modification PB: ls -l sur Documents "2018"
	}
	printf("%s\n", path);//Nom
	//	printf("Type: \n");
	return (1);
}

static	long	prp_length(unsigned int nbr)
{
	long i;

	i = 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static void	max_info(t_dir *list, t_max *max)
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
			? max->links : (int)list->file_info->st_nlink;//Nombre de liens
		if (getpwuid(list->file_info->st_uid) != NULL)
			max->prp = ft_strlen(getpwuid(list->file_info->st_uid)->pw_name)
				? max->prp : ft_strlen(getpwuid(list->file_info->st_uid)->pw_name);
		else
			max->prp = max->prp > prp_length(list->file_info->st_uid)
				? max->prp : prp_length(list->file_info->st_uid);
		max->grp = max->grp > ft_strlen(getgrgid(list->file_info->st_gid)->gr_name)
			? max->grp : ft_strlen(getgrgid(list->file_info->st_gid)->gr_name);
		max->size = max->size > list->file_info->st_size
			? max->size : list->file_info->st_size;//Taille
		list = list->next;
	}
}

static int	ft_index(long nbr)
{
	long	y;
	long	i;

	i = 0;
	y = 1;
	while (nbr - y >= 0)
	{
		y *= 10;
		i++;
	}
	return (i);
}

int			print_info_list(int attr, t_dir *list, time_t t)
{
	char	modes[10] = "----------";
	t_max	max;
	long	biggest;
	long	lower;

	if (attr & ARG_l)
	{
		max_info(list, &max);
		printf("total %lld\n", max.total);//Nombre de liens
		while (list)
		{
			printf("%.10s", file_mode(modes, list->file_info->st_mode));//Modes
			if ((biggest = ft_index(max.links)) > (lower = ft_index(list->file_info->st_nlink)))
				while (lower++ < biggest)
					printf(" ");
			printf("  %d", list->file_info->st_nlink);//Nombre de liens
			if (getpwuid(list->file_info->st_uid) == NULL)
			{
				if ((biggest = max.prp) > (lower = prp_length(list->file_info->st_uid)))
					while (lower++ < biggest)
						printf(" ");
				printf(" %ld", (long)list->file_info->st_uid);
			}
			else
			{
				if ((biggest = max.prp) > (lower = ft_strlen(getpwuid(list->file_info->st_uid)->pw_name)))
					while (lower++ < biggest)
						printf(" ");
				printf(" %s", getpwuid(list->file_info->st_uid)->pw_name);//propriétaire
			}
			printf("  %s", getgrgid(list->file_info->st_gid)->gr_name);//Groupe
			if ((biggest = max.grp) > (lower = ft_strlen(getgrgid(list->file_info->st_gid)->gr_name)))
				while (lower++ < biggest)
					printf(" ");
			if ((biggest = ft_index(max.size)) > (lower = ft_index(list->file_info->st_size)))
				while (lower++ < biggest)
					printf(" ");
			printf("  %lld", list->file_info->st_size);//Taille
			if (t - list->file_info->st_mtimespec.tv_sec < 15724800 && t - list->file_info->st_mtimespec.tv_sec > 0)
				printf(" %.12s ", &ctime(&list->file_info->st_mtimespec.tv_sec)[4]);//Date de la dernière modification PB: ls -l sur Documents "2018"
			else
				printf(" %.7s %.4s ", &ctime(&list->file_info->st_mtimespec.tv_sec)[4], &ctime(&list->file_info->st_mtimespec.tv_sec)[20]);//Date de la dernière modification PB: ls -l sur Documents "2018"
			printf("%s\n", list->d_name);//Nom
			list = list->next;
		}
	}
	else
		while (list)
		{
			printf("%s\n", list->d_name);//Nom
			list = list->next;
		}
	//	printf("Type: \n");
	return (1);
}
