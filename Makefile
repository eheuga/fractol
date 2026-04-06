NAME    = fractol
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g

MLX_DIR = ./minilibx-linux
MLX     = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)
MLX_LNK = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCS    = sources/main.c
OBJS    = $(SRCS:.c=.o)

all: $(MLX) $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR) -f Makefile.mk || true

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LNK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -I includes/ -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re