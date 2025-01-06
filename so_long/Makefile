NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar rcs
RM = rm -f

# Add paths to libraries
PRINTF = ./libs/ft_printf
MLX = ./libs/minilibx

SRCS = 	src/main.c \
		src/main_window.c

OBJS = $(SRCS:.c=.o)

HEADER = $(includes/so_long.h)

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin) # macOS
    LIBS = -framework OpenGL -framework AppKit
else # Linux
    LIBS = -lXext -lX11 -lm
endif

all: $(NAME)

# Update compilation to include libraries
$(NAME): $(OBJS)
	make -C $(PRINTF)
	make -C $(MLX)
	$(CC) $(OBJS) -L$(PRINTF) -lftprintf -L$(MLX) -lmlx $(LIBS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(PRINTF) clean
	make -C $(MLX) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(PRINTF) fclean
	make -C $(MLX) clean

re: fclean all

.PHONY: all clean fclean re
