/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:35:55 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/21 18:34:36 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (!s)
		return (NULL);
	while (s && (*s == ' ' || *s == '\t' || *s == '\n') && *s)
		s++;
	a = ft_strlen(s);
	s--;
	while (*(s + a) == ' ' || *(s + a) == '\t' || *(s + a) == '\n')
		a--;
	return (ft_strndup(++s, a));
}
