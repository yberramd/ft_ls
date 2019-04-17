/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:15:04 by bprunevi          #+#    #+#             */
/*   Updated: 2019/02/14 17:45:35 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ten_power(long long a)
{
	if (a > 1)
		return (10 * ten_power(a - 1));
	return (a);
}

long long	sixteen_power(long long a)
{
	if (a > 1)
		return (16 * sixteen_power(a - 1));
	return (a);
}

long long	eight_power(long long a)
{
	if (a > 1)
		return (8 * eight_power(a - 1));
	return (a);
}
