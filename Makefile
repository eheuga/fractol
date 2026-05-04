# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/04 12:00:00 by emheuga           #+#    #+#              #
#    Updated: 2026/05/04 15:05:19 by emheuga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol

SRCS			= sources/main.c sources/draw.c sources/my_put_pixel.c \
				  sources/mandelbrot.c sources/julia.c \
				  sources/color_manager.c sources/print_usage.c \
				  sources/utils/ft_atof.c sources/utils/ft_strcmp.c \
				  sources/hooks/close_window.c sources/hooks/keyhooks.c \
				  sources/hooks/mousehooks.c

BONUS_SRCS		= bonus/burning_ship.c bonus/mandelbar.c

OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

CC				= cc
CFLAGS			= -Werror -Wextra -Wall
RM				= rm -f

MLX_DIR			= minilibx-linux
MLX				= $(MLX_DIR)/libmlx.a
MLX_FLAGS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

%.o : %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -Iinclude -c $< -o $@

all : $(NAME)

$(MLX) :
	make -C $(MLX_DIR)

$(NAME) : $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

bonus : $(MLX) $(OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) $(MLX_FLAGS) -o $(NAME)

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)
	make -C $(MLX_DIR) clean

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
