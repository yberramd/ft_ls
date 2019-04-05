/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 11:10:36 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/26 12:13:12 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*rtn;

	if (!(rtn = malloc(sizeof(t_list))))
		return (NULL);
	rtn->content = NULL;
	if (content)
		rtn->content = ft_strdup(content);
	rtn->content_size = content ? content_size : 0;
	rtn->next = NULL;
	return (rtn);
}
