# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 16:12:54 by fdel-car          #+#    #+#              #
#    Updated: 2016/03/21 17:38:24 by fdel-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = src/main.c src/ft_setpixel.c src/ft_fractal.c src/ft_start.c \
		src/ft_shortcut.c src/ft_color.c

OBJS = main.o ft_setpixel.o ft_fractal.o ft_start.o ft_shortcut.o ft_color.o

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@make re -C libft
	@gcc  -I./includes $(MLXFLAGS) -o $@ $^ ./libft/libft.a
	@echo "\033[1;31m$(NAME) compiled successfully"
	@echo "\033[1A\033[0;39m"

$(OBJS): $(SRCS)
	@clang $(CFLAGS) -c $^ -I./libft/includes -I./includes

clean:
	@make clean -C libft
	@rm -rf $(OBJS)
fclean: clean
	@rm -rf $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
