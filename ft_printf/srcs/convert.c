/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:37:31 by bprunevi          #+#    #+#             */
/*   Updated: 2019/03/14 18:43:45 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_ftoa(double i, t_format format)
{
	long long	t;
	long long	a;
	long long	b;
	int			c;
	int			g;

	c = 0;
	t = (long long)i;
	g = format.accuracy + !t;
	a = t;
	while (t && ++c)
		t /= 10;
	t = chars_before_integer(&format, c + format.accuracy + 1, i < 0, c);
	if (i < 0 && (i *= -1))
		a *= -1;
	format.accuracy = ten_power(format.accuracy + 1);
	b = (long long)(i * format.accuracy) % format.accuracy;
	while (t)
		add_char_to_buff(((a / t) % 10) + 48) && (t /= 10);
	if (format.accuracy > 1 || format.opts.sharp)
		add_char_to_buff('.');
	while (format.accuracy && (format.accuracy /= 10))
		add_char_to_buff(((b / format.accuracy) % 10) + 48);
	while (format.opts.minus && (--format.width - (c + g + 1) > 0))
		add_char_to_buff(' ');
}

void	ft_lltoa(long long i, t_format format)
{
	long long	t;
	int			c;

	c = 0;
	t = i;
	while (t && ++c)
		t /= 10;
	format.accuracy = format.accuracy > c ? format.accuracy : c;
	t = chars_before_integer(&format, format.accuracy, i < 0, format.accuracy);
	while (t)
	{
		c = ((i / t) % 10);
		add_char_to_buff(c * (i < 0 ? -1 : 1) + 48);
		t /= 10;
	}
	if (format.opts.minus)
		while (--format.width - format.accuracy > 0)
			add_char_to_buff(' ');
}

void	ft_llutoa(unsigned long long i, t_format format)
{
	unsigned long long	t;
	int					c;

	c = 0;
	t = i;
	while (t && ++c)
		t /= 10;
	format.accuracy = format.accuracy > c ? format.accuracy : c;
	if (format.width - format.accuracy > 0 && !format.opts.minus
			&& (c = format.opts.zero ? '0' : ' '))
		while (format.width-- - format.accuracy)
			add_char_to_buff(c);
	t = ten_power(format.accuracy);
	while (t)
	{
		add_char_to_buff(((i / t) % 10) + 48);
		t /= 10;
	}
	if (format.opts.minus)
		while (format.width-- - format.accuracy > 0)
			add_char_to_buff(' ');
}

void	ft_llutoa_hex(unsigned long long i, t_format format, char *base_to)
{
	unsigned long long	b;
	int					c;

	c = 0;
	b = i;
	while (b && ++c)
		b /= 16;
	format.accuracy = format.accuracy > c ? format.accuracy : c;
	c = 2 * format.opts.sharp;
	if (format.width - format.accuracy > 0 && !format.opts.minus)
		while (!format.opts.zero && format.width-- - format.accuracy - c)
			add_char_to_buff(' ');
	format.opts.sharp && i ? add_char_to_buff('0') : (void)c;
	format.opts.sharp && i ? add_char_to_buff(base_to[10] + 23) : (void)c;
	if (format.width - format.accuracy > 0 && !format.opts.minus)
		while (format.opts.zero && format.width-- - format.accuracy - c)
			add_char_to_buff('0');
	b = sixteen_power(format.accuracy);
	while (b)
	{
		add_char_to_buff(base_to[(i / b) % 16]);
		b /= 16;
	}
	while (format.opts.minus && format.width-- - format.accuracy - c > 0)
		add_char_to_buff(' ');
}

void	ft_llutoa_oct(unsigned long long i, t_format format)
{
	unsigned long long	b;
	int					c;

	c = 0;
	b = i;
	while (b && ++c)
		b /= 8;
	format.accuracy = (format.accuracy > c ? format.accuracy : c);
	format.accuracy += format.opts.sharp;
	if (format.width - format.accuracy > 0 && !format.opts.minus)
	{
		if (!format.opts.zero)
			while (format.width-- - format.accuracy)
				add_char_to_buff(' ');
		else
			while (format.width-- - format.accuracy)
				add_char_to_buff('0');
	}
	b = eight_power(format.accuracy + 1);
	while (b && (b /= 8))
		add_char_to_buff((i / b) % 8 + 48);
	if (format.opts.minus)
		while (format.width-- - format.accuracy > 0)
			add_char_to_buff(' ');
}
