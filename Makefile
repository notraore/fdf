# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: notraore <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/22 16:56:22 by lramirez          #+#    #+#              #
#    Updated: 2017/06/12 16:10:14 by notraore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
CC=gcc
SRC=main.c errors.c key_input.c bresenham.c
OBJ=main.o errors.o key_input.o bresenham.o
FLAGS=-Wall -Wextra -Werror
LIB=./libft/libft.a
MLX=-L ./miniLibx -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@ echo "\033[92m\t\t\t---> ✓ libft created. ✓ <---\033[0m"
	@ make -C ./libft
	@ echo "\033[92m\t---> ✓ fdf program has been successfully created. ✓ <---\033[0m"
	@ $(CC) $(FLAGS) $(OBJ) -o $(NAME) $(MLX) $(LIB)
$(OBJ): $(SRC)
	@ $(CC) $(FLAGS) -c $(SRC)
clean:
	@ echo "\033[1;33m---> All .o files cleared. ✓ <---\033[0m"
	@ rm -f $(OBJ)
	@ make -C ./libft clean
fclean: clean
	@ echo "\033[1;33m---> Everything has been cleared. ✓ <---\033[2;00m"
	@ rm -f $(NAME)
	@ make -C ./libft fclean
re: fclean all

.PHONY: clean, fclean, re
