/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:56:26 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/26 10:22:02 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa_base(int nbr, char *base_to)
{
	int		a;
	int		b;
	int		c;
	char	*final;

	a = ft_strlen(base_to);
	c = 0;
	b = nbr;
	while (b)
	{
		c++;
		b /= a;
	}
	final = (char *)malloc(c + 1);
	b = c + 1;
	while (c + 1 > 0)
	{
		final[c-- - 1] = (nbr % a) + 48;
		nbr /= a;
	}
	final[b - 1] = '\0';
	return (final);
}
