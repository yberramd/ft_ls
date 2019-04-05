/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:53:59 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/24 16:12:54 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *tab, char (*f)(unsigned int, char))
{
	char	*rtn;
	int		i;

	i = 0;
	if (!tab || !f || !(rtn = ft_strdup(tab)))
		return (NULL);
	while (rtn && rtn[i++])
		rtn[i - 1] = f(i - 1, rtn[i - 1]);
	return (rtn);
}
