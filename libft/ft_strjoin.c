/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:00:34 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/07 11:15:49 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *rtn;

	rtn = NULL;
	if (!s1 || !s2 ||
		!(rtn = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_bzero(rtn, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcpy(rtn, s1);
	ft_strcat(rtn, s2);
	return (rtn);
}
