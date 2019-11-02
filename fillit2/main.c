#include "fillit.h"

int     main()
{
    int         fd;
    int         i;
    v_list      *lst;

    fd = open("igor2", O_RDONLY);
    if (fd == -1)
        ft_putstr("error\n");
    lst = init_list();
    i = ft_validation(&lst, fd);
    if (i == 0)
        ft_putstr("error\n");
    else
        ft_putstr("continue\n");
    close(fd);
    return (0);
}