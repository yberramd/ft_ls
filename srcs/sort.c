/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:05:26 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/17 14:34:41 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	cmp(int attr, t_dir *elem1, t_dir *elem2)
{
	int	i;

	i = 0;
	if (attr & ARG_t && attr & ARG_r)
		return (elem1->file_info->st_mtimespec.tv_sec >
				elem2->file_info->st_mtimespec.tv_sec);
	if (attr & ARG_t)
		return (elem1->file_info->st_mtimespec.tv_sec <
				elem2->file_info->st_mtimespec.tv_sec);
	while (elem1->d_name[i] == elem2->d_name[i])
		++i;
	i = elem1->d_name[i] > elem2->d_name[i];
	if (attr & ARG_r)
		return (!i);
	return (i);
}

int	sort(int attr, t_dir *list)
{
	void	*tmp;
	int		witness;

	witness = 0;
	while (list->next)
	{
		if (cmp(attr, list, list->next))
		{
			tmp = list->d_name;
			list->d_name = list->next->d_name;
			list->next->d_name = tmp;
			tmp = list->file_info;
			list->file_info = list->next->file_info;
			list->next->file_info = tmp;
			witness = 1;
		}
		list = list->next;
	}
	return (witness);
}
