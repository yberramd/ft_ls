/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:20:31 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/08 16:08:35 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char *rtn;

	rtn = NULL;
	if (!s1 || !s2 ||
		!(rtn = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	bzero(rtn, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcpy(rtn, s1);
	ft_strcat(rtn, s2);
	free((void *)s1);
	free((void *)s2);
	return (rtn);
}
