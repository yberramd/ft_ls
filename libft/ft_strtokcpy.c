/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtokcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:51:55 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/07 09:37:14 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtokcpy(char *str, const char *delim)
{
	static char *s;
	int			i;

	if (str)
		s = str;
	if (str && ft_strchr(delim, str[0]))
		return (ft_strdup(""));
	if (!s || !*s)
		return (NULL);
	i = 0;
	while (!ft_strchr(delim, s[i]))
		i++;
	str = s;
	s = &s[i];
	if (!i)
	{
		s++;
		if (ft_strchr(delim, str[i + 1]))
			return (ft_strdup(""));
		return (ft_strtokcpy(s, delim));
	}
	return (ft_strndup(str, i));
}
