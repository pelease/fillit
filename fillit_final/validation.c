/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvilma <lvilma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:10:39 by lvilma            #+#    #+#             */
/*   Updated: 2019/12/06 15:59:03 by lvilma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				validation(t_lst **lst, int fd, int *size)
{
	int			num;
	char		buff[BUFF_SIZE + 1];
	char		c;
	int			flag;

	c = 'A';
	while ((num = read(fd, buff, BUFF_SIZE)) > 0)
	{
		flag = 0;
		buff[num] = '\0';
		if (num < BUFF_SIZE - 1)
			return (0);
		*lst = (*size == 0) ? init_list() : addelem(*lst);
		if (tetr_form_chkr(*lst, buff) == 0 || touch_checker(*lst) == 0)
			return (0);
		(*lst)->name = c;
		c++;
		(*size)++;
		if (buff[20] == '\n')
			flag = 1;
	}
	if (flag == 1 || *size == 0 || *size > 26)
		return (0);
	points(lst);
	return (1);
}

static void		filling_arr_limit(t_lst *lst, int i, int n, int amt)
{
	lst->mtx[0][amt - 1] = (i - 5 * n) - lst->x;
	lst->mtx[1][amt - 1] = n - lst->y;
	if (lst->arr[0] > lst->mtx[0][amt - 1])
		lst->arr[0] = lst->mtx[0][amt - 1];
	if (lst->arr[1] < lst->mtx[0][amt - 1])
		lst->arr[1] = lst->mtx[0][amt - 1];
	if (lst->arr[2] < lst->mtx[1][amt - 1])
		lst->arr[2] = lst->mtx[1][amt - 1];
}

static	int		not_new_line(int i, int *n, char *buff)
{
	if (i == ((4 + 5 * *n)) && buff[i] != '\n')
		return (0);
	if (i == ((4 + 5 * *n)) && buff[i] == '\n')
		(*n)++;
	if (i == 20 && buff[i] != '\n')
		return (0);
	return (1);
}

static int		if_right_sign(int n, char *buff, int amt, t_lst *lst)
{
	int			i;

	i = 0;
	while (buff[i] != '\0')
	{
		if ((buff[i] == '#' && amt >= 4) || (amt < 4 && buff[i + 1] == '\0'))
			return (0);
		if (i != ((4 + 5 * n)) && i != 20 && buff[i] != '#' && buff[i] != '.')
			return (0);
		if (i != 4 + 5 * n && i != 20 && buff[i] == '#')
		{
			if (amt == 0)
			{
				lst->x = i - 5 * n;
				lst->y = n;
			}
			else
				filling_arr_limit(lst, i, n, amt);
			amt++;
		}
		if (not_new_line(i, &n, buff) == 0)
			return (0);
		i++;
	}
	return (1);
}

int				tetr_form_chkr(t_lst *lst, char *buff)
{
	int			i;
	int			n;
	int			amt;

	i = 0;
	n = 0;
	amt = 0;
	while (i < 3)
		lst->arr[i++] = 0;
	return (if_right_sign(n, buff, amt, lst));
}
