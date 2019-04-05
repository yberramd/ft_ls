/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:01:17 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/24 16:29:00 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			a;
	unsigned char	*c1;
	unsigned char	*c2;

	if (n == 0)
		return (0);
	a = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (c1[a] == c2[a] && a != n - 1)
		a++;
	return (c1[a] - c2[a]);
}
