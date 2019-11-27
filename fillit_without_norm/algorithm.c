#include "fillit.h"

int     algorithm(v_list *lst, int size)
{
    int i;
    int check = 0;
    int m;
    int n;
    char **matrix;

    i = 0;
    //printf("algorithm_started\n");
    //printf("size = %d\n", size);
    while (i * i < size * 4)
        i++;
    /* print_map(i, matrix); */
    while (i < 27)
    {
        //printf("circle with i = %d started\n", i);
        matrix = making_map(i);
        //print_map(i, matrix);
        while (lst)
        {
            //printf("circle with lst started\n");
            if (lst->y < 0)
                m = 0;
            else
            {
                m = lst->y;
                lst->y = -1;
            }
            while (m < i)
            {
                if (lst->x < 0)
                    n = 0;
                else
                {
                    n = lst->x + 1;
                    lst->x = -1;
                }
                while (matrix[m][n] != '\0')
                {
                    //printf("circle with n started\n");
                    if (n + lst->arr[0] < 0)
                    {
                        //printf("in\n");
                        n++;
                    }
                    else if (n + lst->arr[1] >= i)
                    {
                        //printf("in\n");
                        break ;
                    }
                    else if (m + lst->arr[2] >= i)
                        break ;
                    else if (matrix[m + lst->matrix[1][0]][n + lst->matrix[0][0]] != '.'
                            || matrix[m + lst->matrix[1][1]][n + lst->matrix[0][1]] != '.'
                            || matrix[m + lst->matrix[1][2]][n + lst->matrix[0][2]] != '.'
                            || matrix[m][n] != '.')
                    {
                        //print_map(i, matrix);
                        //printf("in\n");
                        n++;
                    }
                    else
                    {
                        lst->x = n;
                        lst->y = m;
                        matrix[m][n] = lst->name;
                        matrix[m + lst->matrix[1][0]][n + lst->matrix[0][0]] = lst->name;
                        matrix[m + lst->matrix[1][1]][n + lst->matrix[0][1]] = lst->name;
                        matrix[m + lst->matrix[1][2]][n + lst->matrix[0][2]] = lst->name;
                        //printf("in\n");
                        break ;
                    }
                }
                if (m + lst->arr[2] >= i)
                    break ;
                if (lst->x >= 0 || lst->y >= 0)
                    break ;
                m++;
            }
            if ((lst->x < 0 || lst->y < 0) && lst->prev != NULL)
            {
                lst = lst->prev;
                matrix[lst->y][lst->x] = '.';
                matrix[lst->y + lst->matrix[1][0]][lst->x + lst->matrix[0][0]] = '.';
                matrix[lst->y + lst->matrix[1][1]][lst->x + lst->matrix[0][1]] = '.';
                matrix[lst->y + lst->matrix[1][2]][lst->x + lst->matrix[0][2]] = '.';

            }
            else if ((lst->x < 0 || lst->y < 0) && lst->prev == NULL)
                break ;
            else
                lst = lst->next;
        }
        if (lst == NULL)
        {
            //printf("algorithm_started\n");
            print_map(i, matrix);
            matrix = delete_map(i, matrix);
            return (1);
        }
        matrix = delete_map(i, matrix);
        i++;
    }
    return (0);
}