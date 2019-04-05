/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:34:18 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/24 21:08:40 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *s)
{
	int		neg;
	int		rtn;
	char	*str;

	str = (char *)s;
	if (*str == ' ' || *str == '\t' || *str == '\v' ||
		*str == '\n' || *str == '\r' || *str == '\f')
		return (ft_atoi((const char *)++str));
	neg = 1;
	rtn = 0;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str > 47 && *str < 58)
		rtn = (rtn * 10) + (*str++ - 48);
	return (rtn * neg);
}
