/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:54:14 by bprunevi          #+#    #+#             */
/*   Updated: 2018/12/13 15:12:54 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *src, size_t size)
{
	char		*dest;
	size_t		a;
	size_t		len;

	a = 0;
	len = ft_strlen(src) + 1;
	len = size < len ? size : len;
	if (!(dest = (char *)malloc(len + 1)))
		return (NULL);
	while (dest && a++ <= len)
		dest[a - 1] = src[a - 1];
	dest[a - 2] = '\0';
	return (dest);
}
