/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:06:38 by bprunevi          #+#    #+#             */
/*   Updated: 2019/03/14 18:51:11 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

struct s_params params;

long long	next_arg(unsigned char *c, char b)
{
	if (b)
	{
		if (*(c + 1) == 'l')
			return (va_arg(params.ap, long long));
		else if (*c == 'l')
			return ((long long)va_arg(params.ap, long));
		return ((long long)va_arg(params.ap, int));
	}
	if (*(c + 1) == 'l')
		return (va_arg(params.ap, unsigned long long));
	else if (*c == 'l')
		return ((long long)va_arg(params.ap, unsigned long));
	return ((long long)va_arg(params.ap, unsigned int));
}

void		solve_float(t_format format)
{
	double f;

	if ((format.type == 'f' || format.type == 'F')
			&& (f = va_arg(params.ap, double)))
		if (ft_floattest(f, format))
			ft_ftoa(f, format);
}

void		solve(t_format format)
{
	if (format.type != 'f' && format.type != 'F' && format.accuracy != -1)
		format.opts.zero = 0;
	if (format.accuracy == -1 && format.type != 's')
		format.accuracy = format.type == 'f' || format.type == 'F' ? 6 : 1;
	if (format.type == 'd' || format.type == 'i')
		ft_lltoa(next_arg(format.size, 1), format);
	else if (format.type == 's')
		ft_stoa(va_arg(params.ap, char *), format);
	else if (format.type == 'c')
		ft_ctoa(va_arg(params.ap, int), format);
	else if (format.type == '%')
		ft_ctoa('%', format);
	else if (format.type == 'u')
		ft_llutoa(next_arg(format.size, 0), format);
	else if (format.type == 'o')
		ft_llutoa_oct(next_arg(format.size, 0), format);
	else if (format.type == 'p' && (format.opts.sharp = 1))
		ft_llutoa_hex(va_arg(params.ap, unsigned long long), format,
		"0123456789abcdef");
	else if (format.type == 'x')
		ft_llutoa_hex(next_arg(format.size, 0), format, "0123456789abcdef");
	else if (format.type == 'X')
		ft_llutoa_hex(next_arg(format.size, 0), format, "0123456789ABCDEF");
	solve_float(format);
}

int			first_char(int t, t_opts opts)
{
	if (t)
		add_char_to_buff('-');
	else if (opts.plus)
		add_char_to_buff('+');
	else if (opts.space)
		add_char_to_buff(' ');
	else
		return (1);
	return (0);
}

long long	chars_before_integer(t_format *format, int c, int t, int x)
{
	if (format->width - c > 0 && !format->opts.minus)
	{
		if (!format->opts.zero)
			while (--format->width - c + !x)
				add_char_to_buff(' ');
		if (first_char(t, format->opts) && x)
			add_char_to_buff(format->opts.zero ? '0' : ' ');
		if (format->opts.zero)
			while (--format->width - c)
				add_char_to_buff('0');
	}
	else if (first_char(t, format->opts))
		format->width += 1;
	if (!x && format->accuracy)
		add_char_to_buff('0');
	else
		return (ten_power(x));
	return (0);
}
