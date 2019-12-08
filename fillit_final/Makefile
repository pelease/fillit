# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pelease <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/06 18:14:11 by pelease           #+#    #+#              #
#    Updated: 2019/12/06 18:14:17 by pelease          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c validation.c algorithm.c listmaker.c map.c touch_checker.c

OBJ = main.o validation.o algorithm.o listmaker.o map.o touch_checker.o

LIB = libft/libft.a

INC = ./

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(FLAGS) -c $(SRC) -I $(INC)
	@gcc $(FLAGS) $(OBJ) $(LIB) -I $(INC) -o $(NAME)

clean:
	@make fclean -C libft/
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
