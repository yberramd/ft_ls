/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:26:51 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/24 16:34:33 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)src;
	while (i < n)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			ft_memcpy(dst, src, i + 1);
			return (&dst[i + 1]);
		}
		i++;
	}
	ft_memcpy(dst, src, n);
	return (NULL);
}
