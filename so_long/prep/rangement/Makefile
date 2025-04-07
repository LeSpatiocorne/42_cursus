NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar rcs
RM = rm -f

PRINTF = ./libs/ft_printf
LIBFT = ./libs/ft_printf/libft
GNL = ./libs/get_next_line

SRCS = 	src/main.c \
		src/main_window.c \
		src/map.c \
		src/player.c \
		src/coin.c \
		src/exit.c

OBJS = $(SRCS:.c=.o)

HEADER = $(includes/so_long.h)

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin) # macOS
    MLX = ./libs/minilibx/opengl
    LIBS = -framework OpenGL -framework AppKit
else # Linux
    MLX = ./libs/minilibx/linux
    LIBS = -lXext -lX11 -lm
endif

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTF)
	make -C $(GNL)
	make -C $(MLX)
	$(CC) $(OBJS) -L$(PRINTF) -lftprintf -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(MLX) -lmlx $(LIBS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I includes -I$(PRINTF) -I$(LIBFT) -I$(GNL) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(PRINTF) clean
	make -C $(GNL) clean
	make -C $(MLX) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(PRINTF) fclean
	make -C $(GNL) fclean

re: fclean all

.PHONY: all clean fclean re
