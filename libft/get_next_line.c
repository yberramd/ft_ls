/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:51:16 by bprunevi          #+#    #+#             */
/*   Updated: 2019/01/24 12:10:19 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int		get_next_line(int fd, char **line)
{
	static char	*buffer = NULL;
	char		*tmp;
	int			rtn;

	tmp = NULL;
	if (!(rtn = 1) || BUFF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	*line = ft_strnew(0);
	if (!buffer && (buffer = ft_strnew(BUFF_SIZE)))
		rtn = read(fd, buffer, BUFF_SIZE);
	while (!ft_strchr(buffer, '\n') && !(rtn < 1) && !(!rtn && *line[0]))
	{
		*line = ft_strjoinfree(*line, ft_strdup(buffer));
		ft_bzero(buffer, BUFF_SIZE);
		rtn = read(fd, buffer, BUFF_SIZE);
	}
	if (rtn < 1 || (!rtn && *line[0]))
		return ((!rtn && *line[0]) ? 1 : rtn);
	*line = ft_strjoinfree(*line, ft_strtokcpy(buffer, "\n"));
	if (ft_strchr(buffer, '\n'))
		tmp = ft_strcpy(ft_strnew(BUFF_SIZE), ft_strchr(buffer, '\n') + 1);
	ft_memdel((void **)&buffer);
	buffer = tmp ? tmp : buffer;
	return (rtn > 0);
}
