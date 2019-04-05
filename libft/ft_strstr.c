/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:42:27 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/26 14:01:01 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	int		a;
	char	*s;
	char	*tf;

	i = 0;
	j = 0;
	s = (char *)str;
	tf = (char *)to_find;
	if (!*tf)
		return (s);
	while (str[i])
	{
		a = i;
		if (str[i] == to_find[0])
			while ((str[i++] == to_find[j++]))
				if ((!to_find[j]) || (str[i] == to_find[j] && !to_find[j + 1]))
					return (&s[i - j]);
		j = 0;
		i = a + 1;
	}
	return (NULL);
}
