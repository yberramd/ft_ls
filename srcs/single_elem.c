/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:51:34 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/07 16:32:01 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "../libft/libft.h"

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
	return (str);
}

int			print_info(const char *path, int attr)
{
	struct stat file_info;
	char modes[10] = "----------";

	if (stat(path, &file_info))
		return(printf("ls: %s: No such file or directory\n", path) & 0);
	if (attr & ARG_l)
	{
		printf("%.10s", file_mode(modes, file_info.st_mode));//Modes
		printf("  %d", file_info.st_nlink);//Nombre de liens
		printf(" %s", getpwuid(file_info.st_uid)->pw_name);//propriétaire
		printf("  %s", getgrgid(file_info.st_gid)->gr_name);//Groupe
		printf("  %lld", file_info.st_size);//Taille
		printf(" %.12s ", &ctime(&file_info.st_mtimespec.tv_sec)[4]);//Date de la dernière modification
	}
	printf("%s\n", path);//Nom
	//	printf("Type: \n");
	return (1);
}

int			print_info_list(int attr, t_dir *list)
{
	char			modes[10] = "----------";
	long long int	total;
	t_dir			*tmp;

	tmp = list;
	total = 0;
	if (attr & ARG_l)
	{
		while (list)
		{
			total += list->file_info->st_blocks;
	//		printf("  %d", tmp->file_info->st_nlink);//Nombre de liens
	//		printf(" %s", getpwuid(list->file_info->st_uid)->pw_name);//propriétaire
	//		printf(" %s", getgrgid(list->file_info->st_gid)->gr_name);//Groupe
	//		printf(" %lld", list->file_info->st_size);//Taille
	//		printf(" %.12s ", &ctime(&list->file_info->st_mtimespec.tv_sec)[4]);//Date de la dernière modification
			list = list->next;
		}
		printf("total %lld\n", total);//Nombre de liens
		while (tmp)
		{
			printf("%.10s", file_mode(modes, tmp->file_info->st_mode));//Modes
			printf("  %d", tmp->file_info->st_nlink);//Nombre de liens
			getpwuid(tmp->file_info->st_uid) == NULL
			? printf(" %ld", (long)tmp->file_info->st_uid)
			: printf(" %s", getpwuid(tmp->file_info->st_uid)->pw_name);//propriétaire
			printf("  %s", getgrgid(tmp->file_info->st_gid)->gr_name);//Groupe
			printf("  %lld", tmp->file_info->st_size);//Taille
			printf(" %.12s ", &ctime(&tmp->file_info->st_mtimespec.tv_sec)[4]);//Date de la dernière modification PB: ls -l sur Documents "2018"
			printf("%s\n", tmp->d_name);//Nom
			tmp = tmp->next;
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
