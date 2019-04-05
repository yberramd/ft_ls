/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:31:15 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/26 14:01:01 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	a;
	char	*s;
	char	*tf;

	i = 0;
	j = 0;
	a = 0;
	s = (char *)str;
	tf = (char *)to_find;
	if (!*tf || str == to_find)
		return (s);
	while (str[i] && i <= len)
	{
		a = i;
		if (str[i] == to_find[0])
			while ((str[i++] == to_find[j++]) && i <= len)
				if ((!to_find[j]) || (str[i] == to_find[j] && !to_find[j + 1]))
					return (&s[i - j]);
		j = 0;
		i = a;
		i++;
	}
	return (NULL);
}
