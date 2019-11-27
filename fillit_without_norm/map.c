#include "fillit.h"

char    **making_map(int size)
{
    int     i;
    int     j;
    char    **matrix;

    i = 0;
    matrix = (char**)malloc(sizeof(char*) * (size + 1));
    while (i < size)
    {
        matrix[i] = (char*)malloc(sizeof(char) * (size + 1));
        j = 0;
        while (j < size)
            matrix[i][j++] = '.';
        matrix[i][j] = '\0';
        i++;
    }
    return (matrix);
}

char    **delete_map(int size, char **matrix)
{
    int i;

    i = 0;
    while (i < size)
    {
        free(matrix[i]);
        matrix[i] = NULL;
        i++;
    }
    free(matrix);
    matrix = NULL;
    return(matrix);
}

void    print_map(int size, char **matrix)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (matrix[i][j] != '\0')
        {
            ft_putchar(matrix[i][j]);
            j++;
        }
        ft_putchar(10);
        i++;
    }
}