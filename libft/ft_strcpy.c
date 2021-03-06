/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:57:09 by bprunevi          #+#    #+#             */
/*   Updated: 2018/12/13 12:18:05 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	int a;

	a = -1;
	while (src[++a])
		dest[a] = src[a];
	dest[a] = '\0';
	return (dest);
}
