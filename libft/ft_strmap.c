/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:42:21 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/24 16:17:26 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *tab, char (*f)(char))
{
	char	*rtn;
	int		a;

	a = 0;
	if (!tab || !f || !(rtn = ft_strdup(tab)))
		return (NULL);
	while (rtn && rtn[a])
	{
		rtn[a] = f(rtn[a]);
		a++;
	}
	return (rtn);
}
