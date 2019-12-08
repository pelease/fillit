/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvilma <lvilma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:11:59 by lvilma            #+#    #+#             */
/*   Updated: 2019/12/05 23:41:03 by lvilma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21

# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

typedef struct		s_lst
{
	int				x;
	int				y;
	char			name;
	int				mtx[2][3];
	int				arr[3];
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_map
{
	int				n;
	int				m;
	char			i;
}					t_map;

t_lst				*init_list(void);
t_lst				*addelem(t_lst *lst);
t_lst				*deletelem(t_lst *lst);
int					validation(t_lst **lst, int fd, int *size);
int					tetr_form_chkr(t_lst *lst, char *buff);
int					touch_checker(t_lst *lst);
int					algorithm(t_lst *lst, int size);
char				**making_map(int size);
void				points(t_lst **lst);
char				**delete_map(int size, char **matrix);
void				print_map(int size, char **matrix);

#endif
