/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvilma <lvilma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 21:42:43 by lvilma            #+#    #+#             */
/*   Updated: 2019/12/05 23:11:30 by lvilma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		check_tetrim_column(t_map *mp, char **mtx, t_lst *lst)
{
	while (mtx[mp->m][mp->n] != '\0')
	{
		if (mp->n + lst->arr[0] < 0)
			(mp->n)++;
		else if (mp->n + lst->arr[1] >= mp->i || mp->m + lst->arr[2] >= mp->i)
			break ;
		else if (mtx[mp->m + lst->mtx[1][0]][mp->n + lst->mtx[0][0]] != '.'
				|| mtx[mp->m + lst->mtx[1][1]][mp->n + lst->mtx[0][1]] != '.'
				|| mtx[mp->m + lst->mtx[1][2]][mp->n + lst->mtx[0][2]] != '.'
				|| mtx[mp->m][mp->n] != '.')
			(mp->n)++;
		else
		{
			lst->x = mp->n;
			lst->y = mp->m;
			mtx[mp->m][mp->n] = lst->name;
			mtx[mp->m + lst->mtx[1][0]][mp->n + lst->mtx[0][0]] = lst->name;
			mtx[mp->m + lst->mtx[1][1]][mp->n + lst->mtx[0][1]] = lst->name;
			mtx[mp->m + lst->mtx[1][2]][mp->n + lst->mtx[0][2]] = lst->name;
			break ;
		}
	}
}

static void		check_tetrim_lines(t_map *mp, char **mtx, t_lst *lst)
{
	while (mp->m < mp->i)
	{
		if (lst->x < 0)
			mp->n = 0;
		else
		{
			mp->n = lst->x + 1;
			lst->x = -1;
		}
		check_tetrim_column(mp, mtx, lst);
		if (mp->m + lst->arr[2] >= mp->i)
			break ;
		if (lst->x >= 0 || lst->y >= 0)
			break ;
		(mp->m)++;
	}
}

static void		check_lst(t_map *mp, char **mtx, t_lst **l)
{
	while (*l)
	{
		if ((*l)->y < 0)
			mp->m = 0;
		else
		{
			mp->m = (*l)->y;
			(*l)->y = -1;
		}
		check_tetrim_lines(mp, mtx, *l);
		if (((*l)->x < 0 || (*l)->y < 0) && (*l)->prev != NULL)
		{
			(*l) = (*l)->prev;
			mtx[(*l)->y][(*l)->x] = '.';
			mtx[(*l)->y + (*l)->mtx[1][0]][(*l)->x + (*l)->mtx[0][0]] = '.';
			mtx[(*l)->y + (*l)->mtx[1][1]][(*l)->x + (*l)->mtx[0][1]] = '.';
			mtx[(*l)->y + (*l)->mtx[1][2]][(*l)->x + (*l)->mtx[0][2]] = '.';
		}
		else if (((*l)->x < 0 || (*l)->y < 0) && (*l)->prev == NULL)
			break ;
		else
			(*l) = (*l)->next;
	}
}

int				algorithm(t_lst *lst, int size)
{
	t_map		*mp;
	char		**mtx;

	mp = (t_map*)malloc(sizeof(t_map));
	mp->i = 0;
	while (mp->i * mp->i < size * 4)
		(mp->i)++;
	while (mp->i < 27)
	{
		mtx = making_map(mp->i);
		check_lst(mp, mtx, &lst);
		if (lst == NULL)
		{
			print_map(mp->i, mtx);
			mtx = delete_map(mp->i, mtx);
			free(mp);
			mp = NULL;
			return (0);
		}
		mtx = delete_map(mp->i, mtx);
		(mp->i)++;
	}
	free(mp);
	mp = NULL;
	return (0);
}
