/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:05:26 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/05 11:00:12 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int cmp(int attr, t_dir *elem1, t_dir *elem2)
{
	int i;

	i = 0;

	// le -r n'est pas encore parfait.
	// en cas d'egalite, le mien n'inverse pas les valeurs egales, alors que ls -r oui.
	// que faire ? on fait l'inversion a l'affichage ?
	// ce serait chiant de faire une liste a double sens pour ca quand meme...

	if (attr & ARG_t && attr & ARG_r)
		return(elem1->file_info->st_mtimespec.tv_sec >
			elem2->file_info->st_mtimespec.tv_sec);
	if (attr & ARG_t)
		return(elem1->file_info->st_mtimespec.tv_sec <
			elem2->file_info->st_mtimespec.tv_sec);
	while (elem1->dirent->d_name[i] == elem2->dirent->d_name[i])
		++i;
	i = elem1->dirent->d_name[i] > elem2->dirent->d_name[i];
	if (attr & ARG_r)
		return(!i);
	return(i);
}

int sort(int attr, t_dir *list)
{
	void	*tmp;
	int witness = 0;
	while (list->next)
	{
		if (cmp(attr, list, list->next))
		{
			tmp = list->dirent;
			list->dirent = list->next->dirent;
			list->next->dirent = tmp;
			tmp = list->file_info;
			list->file_info = list->next->file_info;
			list->next->file_info = tmp;
			witness = 1;
		}
		list = list->next;
	}
	return(witness);
}
