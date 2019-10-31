/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:26:18 by pelease           #+#    #+#             */
/*   Updated: 2019/10/30 13:26:23 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int             ft_validation(v_list *lst, int fd)
{
    int         t;
    char        buff[BUFF_SIZE + 1];
    int         n;
    int         i;

    i = 0;
    while ((n = read(fd, buff, BUFF_SIZE)) > 0)
    {
        buff[n] = "\0";
        n = 0;
        t = -1;
        if (i != 0)
            lst = addelem(lst);
        if (ft_valid2(lst, buff, &t, &n) == 0 || ft_valid3(lst) == 0)
            return (0);
        i++;
    }
    if (i == 0 || i > 26)
    {   
        while (--i + 1 > 0)
            lst = deletelem(lst);
        return (0);
    }
    return (1);
}

int             ft_valid2(v_list *lst, char *buff, int *t, int *n)
{
    int         i;

    i = 0;
    while (buff[i])
    {
        if ((i == (4 + 5 * *n) || i == 20) && (buff[i] = "\n"))
            if (i++ == (4 + 5 * *n))
                (*n)++;
        else if ((buff[i] == "." || buff[i] == "#") && *t < 4)
        {
            if (buff[i++] == "#" && (*t)++ == -1)
            {
                lst->x = (i - 1) - 5 * *n;
                lst->y = *n;
            }
            else if (buff[i - 1] == "#" && *t - 1 > -1) 
            {
                lst->matrix[*t - 1][0] = (i - 1) - 5 * *n - lst->x;
                lst->matrix[*t - 1][1] = n - lst->y;
            }
        }
        else
            return (0);
    }
    return (1);
}

int             mod(int n)
{
    if (n < 0)
        n = -n;
    return (n);
}

int            ft_valid3(v_list *lst)
{
    int         m;
    int         s[3];
    int         t;
    int         i;

    m = 0;
    t = 0;
    while (t < 3)
        if ((s[t] = mod(lst->matrix[t][0]) + mod(lst->matrix[t++][1])) == 1)
            m++;
    if (m == 3)
        return (1);
    t = 0;
    while (t < 2)
    {
        i = 1;
        while (t + i < 3)
            if (modul((s[t] - s[t + i++])) == 1)
                m++;
    }
    if (m == 3)
        return (1);
    else
        return (0);
}
