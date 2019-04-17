/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:02:34 by yberramd          #+#    #+#             */
/*   Updated: 2019/04/17 11:37:29 by bprunevi         ###   ########.fr       */
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
		add_char_to_buff(' ');
}
