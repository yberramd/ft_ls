/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:02:34 by yberramd          #+#    #+#             */
/*   Updated: 2019/04/22 11:49:44 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned long	prp_length(unsigned int nbr)
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

int				ft_index(long nbr)
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
	return (!nbr ? 1 : i);
}

void			space(long biggest, long lower)
{
	while (lower++ < biggest)
		ft_printf(" ");
}

int				error(int i, const char *c)
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
	return (0);
}

void			ft_link(char c, const char *path, const char *name)
{
	char	buffer[PATH_MAX + 1];

	if (c == 'l')
	{
		buffer[readlink(path, buffer, PATH_MAX)] = '\0';
		ft_printf("%s", name);
		ft_printf(" -> %s\n", buffer);
	}
	else
		ft_printf("%s\n", name);
}
