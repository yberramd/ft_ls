/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:43:30 by bprunevi          #+#    #+#             */
/*   Updated: 2018/12/13 15:15:34 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char		*dest;
	size_t		len;

	len = ft_strlen(src);
	if (!(dest = ft_strnew(len)))
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}
