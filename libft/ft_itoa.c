/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:49:26 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/24 16:33:31 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int i)
{
	int		t;
	int		c;
	char	*rtn;
	int		neg;

	neg = 0;
	c = 0;
	if (i == -2147483648)
		return (ft_strdup("-2147483648"));
	if (i < 0 && ++neg)
		i *= -1;
	t = i;
	while (t && ++c)
		t /= 10;
	c += neg;
	if (!(rtn = ft_strnew(c + (!i))))
		return (NULL);
	if (neg || !i)
		rtn[0] = neg ? '-' : '0';
	while (i)
	{
		rtn[--c] = (i % 10) + 48;
		i /= 10;
	}
	return (rtn);
}
