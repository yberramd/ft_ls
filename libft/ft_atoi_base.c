/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:55:33 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/25 16:59:47 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *nbr, char *base_from)
{
	int a;
	int b;
	int x;
	int y;
	int final;

	a = ft_strlen(base_from);
	b = ft_strlen(nbr) - 1;
	x = 0;
	y = 0;
	final = 0;
	while (nbr[x])
	{
		while (nbr[x] != base_from[y])
			y++;
		final += y * ft_power(a, b - x);
		x++;
		y = 0;
	}
	return (final);
}
