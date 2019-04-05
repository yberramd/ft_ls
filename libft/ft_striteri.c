/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:26:04 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/24 16:17:57 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *tab, void (*f)(unsigned int, char *))
{
	unsigned int i;

	i = 0;
	if (f && tab)
		while (tab[i++])
			f(i - 1, &tab[i - 1]);
}
