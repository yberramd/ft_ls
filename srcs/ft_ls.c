/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:25 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/03 18:09:47 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ARG_R 1
#define ARG_r 2
#define ARG_t 4
#define ARG_a 8
#define ARG_l 16

#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

typedef struct		s_dir
{
	struct dirent	*dirent;
	struct s_dirent	*next;
}					t_dir;

/*Objectif actuel : creer une liste chainee pour pouvoir aficher les fichiers dans n'importe quel sens.*/

int add_args(char c)
{
	/*ls actuel ne gere pas les arguments incorrects*/
	return( (c == 'R') * ARG_R + 
			(c == 'r') * ARG_r +
			(c == 't') * ARG_t +
			(c == 'a') * ARG_a +
			(c == 'l') * ARG_l);
}

char	*file_mode(char *str, int st_mode)
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

int	print_info(const char *path, int attr)
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

int ls(int attr, const char *path)
{
	DIR *dir;

	(void)attr;
	if (!(dir = opendir(path)))
		return(print_info(path, attr));
	printf("Fichier ouvert !\n");
	closedir(dir);
	return (0);
}

/*
t_dir create_chain(DIR *dir)
{
	t_dir *first_elem;
	return(first_elem);
}
*/

int main(int argc, char **argv)
{
	int i;
	int j;
	int args;

	i = 0;
	args = 0;
	while (++i < argc && argv[i][0] == '-' && !(j = 0))
		while(argv[i][++j])
			args = args | add_args(argv[i][j]);
	if (i == argc)
		return (ls(args, "."));
	while (i < argc)
		ls(args, argv[i++]);
}
