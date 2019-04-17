/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:03:53 by amoynet           #+#    #+#             */
/*   Updated: 2019/04/17 11:22:13 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

struct s_params params;

void		empty_buff(void)
{
	if (params.buff_index)
	{
		write(STDOUT, params.buff, params.buff_index);
		params.len += params.buff_index;
		params.buff_index = 0;
	}
}

void		check_buff(void)
{
	if (params.buff_index >= PRINTF_BUFF_SIZE)
		empty_buff();
}

void		add_sub_to_buff(
	const char *s,
	int len)
{
	int i;

	i = -1;
	while (++i < len)
		add_char_to_buff(s[i]);
}

int			add_char_to_buff(char c)
{
	params.buff[params.buff_index] = c;
	params.buff_index++;
	check_buff();
	return (1);
}
