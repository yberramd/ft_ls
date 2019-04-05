/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:22:42 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/06 11:00:57 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *rtn;

	rtn = NULL;
	rtn = (char *)malloc(size + 1);
	if (rtn)
		ft_bzero(rtn, size + 1);
	return (rtn);
}
