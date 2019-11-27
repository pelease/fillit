#include "fillit.h"
#include <stdio.h>

int         validation(v_list **lst, int fd, int *size)
{
    int     num;
    char    buff[BUFF_SIZE + 1];
    char    c;

    c = 'A';
    while ((num = read(fd, buff, BUFF_SIZE)) > 0)
    {
        buff[num] = '\0';
        if (num < BUFF_SIZE - 1)
        {
            printf("ERR_BUFF\n");
            return (0);
        }
        if (*size == 0)
            *lst = init_list();
        else
            *lst = addelem(*lst);
        if ((val1(*lst, buff)) == 0 || val2(*lst) == 0)
            return (0);
        //printf("i = %d  ", *size);
        (*lst)->name = c;
        c++; 
        (*size)++;
    }
    if (*size == 0 || *size > 26)
    {
            printf("ERR_BUFF\n");
            return (0);
    }
    points(lst);
    return (1);
}

int         val1(v_list *lst, char *buff)
{
    int     i;
    int     n;
    int     amt;

    i = 0;
    n = 0;
    amt = 0;
    while (i < 3)
        lst->arr[i++] = 0;
    i = 0;
    while (buff[i] != '\0')
    {
        if (buff[i] == '#' && amt >= 4 || amt < 4 && buff[i + 1] == '\0')
        {
            printf("11111\n");
            return (0);
        }
        //printf("buff[i] = %c i = %d\n n = %d\n", buff[i], i, n);
        if (i != ((4 + 5 * n)) && i != 20 && buff[i] != '#' && buff[i] != '.')
        {
            //printf("buff[i] = %c i = %d\n", buff[i], i);
            printf("2222\n");
            return (0);
        }
        if (i != 4 + 5 * n && i != 20 && buff[i] == '#')
        {
            if (amt == 0)
            {
                lst->x = i - 5 * n;
                lst->y = n;
            }
            else
            {
                lst->matrix[0][amt - 1] = (i - 5 * n) - lst->x;
                lst->matrix[1][amt - 1] = n - lst->y;
                if (lst->arr[0] > lst->matrix[0][amt - 1])
                    lst->arr[0] = lst->matrix[0][amt - 1];
                if (lst->arr[1] < lst->matrix[0][amt - 1])
                    lst->arr[1] = lst->matrix[0][amt - 1];
                if (lst->arr[2] < lst->matrix[1][amt - 1])
                    lst->arr[2] = lst->matrix[1][amt - 1];
            }
            amt++;
        }
        if (i == ((4 + 5 * n)) && buff[i] != '\n')
        {
            printf("33333\n");
            return (0);
        }    
        if (i == ((4 + 5 * n)) && buff[i] == '\n')
            n++;
        if (i == 20 && buff[i] != '\n')
        {
            printf("44444\n");
            return (0);
        }
        i++;
    }
    return (1);
}

void         sign1(v_list *lst, int *m)
{
    int     i;
    int     arr[3];

    i = -1;
    while (++i < 3)
    {
        if (lst->matrix[0][i] > 0 && lst->matrix[1][i] > 0 || lst->matrix[0][i] <= 0 && lst->matrix[1][i] <= 0)
            arr[i] = lst->matrix[0][i] + lst->matrix[1][i];
        else
            arr[i] = lst->matrix[0][i] - lst->matrix[1][i];
        if (arr[i] == 1 || arr[i] == -1)
            (*m)++;
    }
}

void         sign2(v_list *lst, int *m)
{
    int     i;
    int     j;
    int     k;
    int     s[3];

    i = 0;
    k = 0;
    while (i < 2)
    {
        j = 0;
        while (i + j < 2)
        {
            s[k] = mod((lst->matrix[0][i] - lst->matrix[0][i + j + 1])) + mod((lst->matrix[1][i] - lst->matrix[1][i + j + 1]));
            if (s[k] == 1 || s[k] == -1)
                (*m)++;
            j++;
            k++;
        }
        i++;
    }
}

int         mod(int n)
{
    if (n < 0)
        n = -n;
    return(n);
}

int         val2(v_list *lst)
{
    int     m;

    m = 0;
    sign1(lst, &m);
    sign2(lst, &m);
    //printf("m = %d\n", m);
    if (m < 3)
        return (0);
    return (1);
}