/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:33:34 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/24 20:36:32 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	b;

	b = 0;
	while (b < n)
	{
		if ((unsigned char)c == ((unsigned char*)s)[b])
			return ((void*)(&s[b]));
		b++;
	}
	return (NULL);
}
