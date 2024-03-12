# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 11:26:44 by dliuzzo           #+#    #+#              #
#    Updated: 2024/02/06 17:57:28 by dliuzzo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAG = -Wall -Wextra -Werror -g3

MLX_FLAGS = -lX11 -lXext

INC_LIBFT = -L libft/ -lft

MLX = mlx/libmlx_linux.a

SRCS = main.c \
		game_init.c \
		get_next_line.c \
		get_next_line_utils.c \
		open_map.c \
		liberation.c \
		map_check.c \
		path_check.c \
		events.c \

OBJS = $(SRCS:.c=.o)

NAME = so_long

INCLUDE = -I so_long.h 

all : $(NAME)

%.o: %.c
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJS) 
	make -C libft/ 
	make -C mlx/
	$(CC) $(FLAG) $(OBJS) $(INC_LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME) -lm

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

lclean : 
	make fclean -C libft/

.PHONY: all clean fclean lclean re