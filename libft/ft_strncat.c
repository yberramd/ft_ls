/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:50:14 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/24 20:52:08 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t nb)
{
	size_t dl;
	size_t i;

	i = 0;
	dl = ft_strlen(s1);
	while (s2[i] != '\0' && i < nb)
	{
		s1[dl + i] = s2[i];
		i++;
	}
	s1[dl + i] = '\0';
	return (s1);
}
