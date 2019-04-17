/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:45:37 by bprunevi          #+#    #+#             */
/*   Updated: 2019/03/14 18:52:50 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_ctoa(char c, t_format format)
{
	int i;

	i = 1;
	if (format.opts.zero && format.width && !format.opts.minus)
		while (i++ < format.width)
			add_char_to_buff('0');
	else if (format.width && !format.opts.minus)
		while (i++ < format.width)
			add_char_to_buff(' ');
	add_char_to_buff(c);
	while (i++ < format.width)
		add_char_to_buff(' ');
}

void	ft_stoa(char *c, t_format format)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!c)
		return (ft_stoa("(null)", format));
	if (format.width && !format.opts.minus && (i = ft_strlen(c)))
	{
		i = format.accuracy > 0 && format.accuracy < i ? format.accuracy : i;
		while (i++ < format.width)
			add_char_to_buff(' ');
	}
	while (*c && j++ != format.accuracy && ++i)
		add_char_to_buff(*c++);
	while (i++ < format.width)
		add_char_to_buff(' ');
}

int		ft_floattest(double f, t_format format)
{
	unsigned long *i;

	i = ((unsigned long *)&f);
	if (*i == 0x7FF0000000000000)
	{
		ft_stoa("inf", format);
		return (0);
	}
	if (*i == 0xFFF0000000000000)
	{
		ft_stoa("-inf", format);
		return (0);
	}
	else if (ISNAN(f))
	{
		ft_stoa("nan", format);
		return (0);
	}
	else
		return (1);
}
