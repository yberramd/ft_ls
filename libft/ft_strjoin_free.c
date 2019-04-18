/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:27:20 by yberramd          #+#    #+#             */
/*   Updated: 2019/04/18 10:22:44 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free(char *line, char *buffer, int option)
{
	char	*tmp;

	if (option >= 0 && option <= 3)
	{
		if (!buffer && !line)
			return (NULL);
		if (!(tmp = ft_strjoin(line, buffer)))
			return (NULL);
		if (option == 2 || option == 3)
			ft_strdel(&buffer);
		if (option == 1 || option == 3)
			ft_strdel(&line);
		return (tmp);
	}
	return (NULL);
}
