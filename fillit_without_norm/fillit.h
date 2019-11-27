#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21

# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

typedef struct	val_l
{
	int				x;
	int				y;
	char			name;
	int				matrix[2][3];
	int				arr[3];
	struct val_l	*next;
	struct val_l	*prev;
}				v_list;

v_list			*init_list();
v_list      	*addelem(v_list *lst);
v_list			*deletelem(v_list *lst);
int         	val2(v_list *lst);
void         	sign2(v_list *lst, int *m);
void        	sign1(v_list *lst, int *m);
int         	val1(v_list *lst, char *buff);
int         	validation(v_list **lst, int fd, int *size);
int         	mod(int n);
int     		algorithm(v_list *lst, int size);
char    		**making_map(int size);
void      		points(v_list **lst);
char    		**delete_map(int size, char **matrix);
void    		print_map(int size, char **matrix);

# endif