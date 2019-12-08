/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvilma <lvilma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:10:22 by lvilma            #+#    #+#             */
/*   Updated: 2019/12/05 23:53:14 by lvilma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	int			i;
	int			size;
	t_lst		*lst;

	if (argc != 2)
	{
		ft_putstr_fd("usage: fillit input_file\n", 1);
		return (0);
	}
	size = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putstr("error\n");
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
