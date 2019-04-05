/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:11:31 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/24 16:21:05 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int a;

	a = 0;
	while ((unsigned char)s1[a] == (unsigned char)s2[a])
	{
		if ((unsigned char)s1[a] + (unsigned char)s2[a] == 0)
			return (0);
		a++;
	}
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
