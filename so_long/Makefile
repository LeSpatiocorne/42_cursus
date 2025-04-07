NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -c
RM			= rm -f

PRINTF		= ./libs/ft_printf
LIBFT		= ./libs/ft_printf/libft
GNL			= ./libs/get_next_line

SRCS		= src/main.c \
			  src/main_window.c \
			  src/map.c \
			  src/player.c \
			  src/coin.c \
			  src/exit.c \
			  src/enemy.c

OBJS		= $(SRCS:.c=.o)
HEADER		= includes/so_long.h

UNAME		:= $(shell uname)

ifeq ($(UNAME), Darwin)
	MLX		= ./libs/minilibx/opengl
	LIBS	= -framework OpenGL -framework AppKit
else
	MLX		= ./libs/minilibx/linux
	LIBS	= -lXext -lX11 -lm
endif

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(PRINTF) >/dev/null
	@make -C $(GNL) >/dev/null
	@make -C $(MLX) >/dev/null
	@$(CC) $(OBJS) \
		-L$(PRINTF) -lftprintf \
		-L$(LIBFT) -lft \
		-L$(GNL) -lgnl \
		-L$(MLX) -lmlx \
		$(LIBS) -o $(NAME)
	@echo "✅ Binary created: $(NAME)"

%.o: %.c $(HEADER)
	@echo "🛠️ Compiling $<"
	@$(CC) $(CFLAGS) \
		-I includes -I$(PRINTF) -I$(LIBFT) -I$(GNL) \
		-c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make -C $(PRINTF) clean >/dev/null
	@make -C $(GNL) clean >/dev/null
	@make -C $(MLX) clean >/dev/null
	@echo "🧹 Object files cleaned"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(PRINTF) fclean >/dev/null
	@make -C $(GNL) fclean >/dev/null
	@echo "🧹 Binary removed"

re: fclean all

.PHONY: all clean fclean re
