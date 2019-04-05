/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:38:18 by bprunevi          #+#    #+#             */
/*   Updated: 2018/12/19 09:06:31 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char *s;
	int			i;

	if (str)
		s = str;
	if (!s || !*s)
		return (NULL);
	i = 0;
	while (!ft_strchr(delim, s[i]))
		i++;
	str = s;
	s = &s[i];
	if (!i)
		return (ft_strtok(s + 1, delim));
	if (str[i])
		s += 1;
	str[i] = '\0';
	return (str);
}
