/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:16:47 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/24 20:39:31 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a;

	a = 0;
	if (!n)
		return (0);
	while ((unsigned char)s1[a] == (unsigned char)s2[a])
	{
		if ((unsigned char)s1[a] + (unsigned char)s2[a] == 0 || a == n - 1)
			return (0);
		a++;
	}
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
