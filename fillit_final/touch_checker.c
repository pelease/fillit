/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 23:02:48 by pelease           #+#    #+#             */
/*   Updated: 2019/12/06 23:02:49 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		main_touch(t_lst *lst, int *m)
{
	int			i;
	int			arr[3];

	i = -1;
	while (++i < 3)
	{
		if ((lst->mtx[0][i] > 0 && lst->mtx[1][i] > 0) ||
			(lst->mtx[0][i] <= 0 && lst->mtx[1][i] <= 0))
			arr[i] = lst->mtx[0][i] + lst->mtx[1][i];
		else
			arr[i] = lst->mtx[0][i] - lst->mtx[1][i];
		if (arr[i] == 1 || arr[i] == -1)
			(*m)++;
	}
}

static void		all_touch(t_lst *lst, int *m)
{
	int			i;
	int			j;
	int			k;
	int			s[3];

	i = 0;
	k = 0;
	while (i < 2)
	{
		j = 0;
		while (i + j < 2)
		{
			s[k] = ft_abs((lst->mtx[0][i] - lst->mtx[0][i + j + 1])) +
					ft_abs((lst->mtx[1][i] - lst->mtx[1][i + j + 1]));
			if (s[k] == 1 || s[k] == -1)
				(*m)++;
			j++;
			k++;
		}
		i++;
	}
}

int				touch_checker(t_lst *lst)
{
	int			m;

	m = 0;
	main_touch(lst, &m);
	all_touch(lst, &m);
	if (m < 3)
		return (0);
	return (1);
}
