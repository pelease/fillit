/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmaker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvilma <lvilma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:10:09 by lvilma            #+#    #+#             */
/*   Updated: 2019/12/05 23:47:13 by lvilma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst		*init_list(void)
{
	t_lst	*lst;

	lst = (t_lst*)malloc(sizeof(t_lst));
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

t_lst		*addelem(t_lst *lst)
{
	t_lst	*temp;
	t_lst	*p;

	temp = (t_lst*)malloc(sizeof(t_lst));
	p = lst->next;
	lst->next = temp;
	temp->next = p;
	temp->prev = lst;
	if (p != NULL)
		p->prev = temp;
	return (temp);
}

t_lst		*deletelem(t_lst *lst)
{
	t_lst	*prev;
	t_lst	*next;

	prev = lst->prev;
	next = lst->next;
	if (prev != NULL)
		prev->next = lst->next;
	if (next != NULL)
		next->prev = lst->prev;
	free(lst);
	return (lst->next != NULL ? next : prev);
}

void		points(t_lst **lst)
{
	while ((*lst)->prev)
	{
		(*lst)->x = -1;
		(*lst)->y = -1;
		(*lst) = (*lst)->prev;
	}
	(*lst)->x = -1;
	(*lst)->y = -1;
}
