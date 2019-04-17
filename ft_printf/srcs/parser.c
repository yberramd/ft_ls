/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:21:53 by amoynet           #+#    #+#             */
/*   Updated: 2019/03/14 15:33:54 by amoynet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

struct s_params params;

int		opts_parser(t_format *format, const char *str)
{
	if (*str == '+')
		format->opts.plus = 1;
	else if (*str == '-')
		format->opts.minus = 1;
	else if (*str == '#')
		format->opts.sharp = 1;
	else if (*str == '0')
		format->opts.zero = 1;
	else if (*str == ' ')
		format->opts.space = 1;
	if (format->opts.minus && format->opts.zero)
		format->opts.zero = 0;
	if (format->opts.plus && format->opts.space)
		format->opts.space = 0;
	return (1);
}

int		accuracy_parser(t_format *format, const char *str)
{
	int i;

	i = 1;
	format->accuracy = ft_atoi(str + i);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

int		number_parser(int *n, const char *str)
{
	int i;

	i = 0;
	*n = ft_atoi(str);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

int		size_parser(t_format *format, const char *str)
{
	int i;

	i = 0;
	format->size[0] = *str;
	while (str[++i] && size_char_checker(str[i]))
		if (format->size[0] && format->size[1] && (format->size[0] = str[i]))
			format->size[1] = 0;
		else if (format->size[0] == str[i] && str[i] != 'L')
			format->size[1] = str[i];
		else if ((format->size[0] = str[i]))
			format->size[1] = 0;
	return (i);
}

int		parser(const char *str)
{
	int			i;
	t_format	format;
	t_checker	checker;

	*((__int128*)&format) = 0;
	format.accuracy = -1;
	i = 1;
	while (str[i] && !(*((char*)&checker) = 0)
		&& !(checker.is_type = type_char_checker(str[i])))
		if ((checker.is_accuracy = accuracy_char_checker(str[i])))
			i += number_parser(&format.accuracy, str + i + 1) + 1;
		else if ((checker.is_opt = opt_char_checker(str[i])))
			i += opts_parser(&format, str + i);
		else if ((checker.is_width = width_char_checker(str[i])))
			i += number_parser(&format.width, str + i);
		else if ((checker.is_size = size_char_checker(str[i])))
			i += size_parser(&format, str + i);
		else
			break ;
	if (checker.is_type)
		format.type = str[i];
	solve(format);
	i += checker.is_type || checker.is_accuracy || checker.is_opt
		|| checker.is_width || checker.is_size;
	return (i);
}
