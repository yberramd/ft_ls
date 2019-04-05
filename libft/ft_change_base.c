/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:58:21 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/25 16:59:36 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_change_base(char *nbr, char *base_from, char *base_to)
{
	int a;

	a = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(a, base_to));
}
