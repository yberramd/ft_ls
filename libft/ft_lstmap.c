/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:28:12 by bprunevi          #+#    #+#             */
/*   Updated: 2018/11/26 11:51:39 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *rtn;

	rtn = NULL;
	if (f && lst)
	{
		rtn = f(lst);
		while (lst->next)
		{
			ft_lstaddlast(&rtn, f(lst->next));
			lst = lst->next;
		}
	}
	return (rtn);
}
