/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:43:48 by amoynet           #+#    #+#             */
/*   Updated: 2019/03/01 12:13:05 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			opt_char_checker(char c)
{
	return (
		c == '+'
		|| c == '-'
		|| c == '#'
		|| c == ' '
		|| c == '0');
}

int			type_char_checker(char c)
{
	return (
		c == 'c'
		|| c == 's'
		|| c == 'p'
		|| c == 'd'
		|| c == 'i'
		|| c == 'o'
		|| c == 'u'
		|| c == 'x'
		|| c == 'X'
		|| c == 'f'
		|| c == 'F'
		|| c == '%');
}

int			size_char_checker(char c)
{
	return (
		c == 'h'
		|| c == 'l'
		|| c == 'L');
}

int			width_char_checker(char c)
{
	return (ft_isdigit(c));
}

int			accuracy_char_checker(char c)
{
	return (c == DELIMITER_CHAR);
}
