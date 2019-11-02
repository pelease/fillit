/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:44:10 by pelease           #+#    #+#             */
/*   Updated: 2019/10/30 16:44:16 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21

# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct	val_l
{
	int				x;
	int				y;
	int				matrix[3][2];
	struct val_l	*next;
	struct val_l	*prev;
}				v_list;

int             ft_validation(v_list **lst, int fd);
int             ft_valid2(v_list *lst, char *buff, int *t, int *n);
int             mod(int n);
int				ft_valid3(v_list *lst);
v_list			*init_list();
v_list      	*addelem(v_list *lst);
v_list			*deletelem(v_list *lst);

# endif
