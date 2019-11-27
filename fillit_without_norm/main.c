#include "fillit.h"

int     main()
{
    int         fd;
    int         i;
    int         size;
    v_list      *lst;

    size = 0;
    fd = open("igor2", O_RDONLY);
    if (fd == -1)
        ft_putstr("error\n");
    lst = init_list();
    i = validation(&lst, fd, &size);
    if (i == 0)
        ft_putstr("error\n");
    else
        algorithm(lst, size);
    while (lst)
        lst = deletelem(lst);
    close(fd);
    return (0);
}