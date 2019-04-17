/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:45:41 by amoynet           #+#    #+#             */
/*   Updated: 2019/04/17 15:27:25 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

struct s_params params;

int			ft_printf(const char *format, ...)
{
	int				i;
	int				b;

	i = 0;
	b = 0;
	params.len = 0;
	va_start(params.ap, format);
	while (format[i])
	{
		if (format[i] == '%' || (i++ && 0))
		{
			if (i - b)
				add_sub_to_buff(format + b, i - b);
			b = format[i + 1] == '%' ? i + 1 : i + parser(format + i);
			i = format[i + 1] == '%' ? i + 2 : b;
		}
	}
	if (i - b)
		add_sub_to_buff(format + b, i - b);
	va_end(params.ap);
	return (params.len);
}
