/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:25 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/03 17:18:27 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ARG_R 1
#define ARG_r 2
#define ARG_t 4
#define ARG_a 8
#define ARG_l 16

#include <stdio.h>
#include <dirent.h>

typedef struct		s_dir
{
	struct dirent	*dirent;
	struct s_dirent	*next;
}					t_dir;

/*Objectif actuel : creer une liste chainee pour pouvoir aficher les fichiers dans n'importe quel sens.*/

int add_args(char c)
{
	return( (c == 'R') * ARG_R + 
			(c == 'r') * ARG_r +
			(c == 't') * ARG_t +
			(c == 'a') * ARG_a +
			(c == 'l') * ARG_l);
}

int ls(int attr, const char *path)
{
	DIR *dir;
	if (!(dir = opendir(path)))
		return(0);
	printf("Fichier ouvert !");
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

	args = 0;
	if (argc <= 1)
		return (ls(args, argv[0]));
	while (++i < argc && argv[i][0] == '-' && !(j = 0))
		while(argv[i][++j])
			args = args | add_args(argv[i][j]);
	while (i < argc)
		ls(args, argv[i++]);
}
