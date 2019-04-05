/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:50:38 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/24 16:15:03 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t i;
	size_t j;
	size_t len;

	len = ft_strlen(s1);
	i = len;
	j = 0;
	if (!size)
		return (ft_strlen(s2));
	if (size < len)
		return (ft_strlen(s2) + size);
	while (s2[j] && i < size - 1)
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (len + ft_strlen(s2));
}
