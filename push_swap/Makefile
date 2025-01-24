NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar rcs
RM = rm -f

PRINTF = ./libs/ft_printf
GET_NEXT_LINE = ./libs/get_next_line
LIBFT = ./libs/libft
SRCS = 	srcs/main.c \
		srcs/algorithm/algo1.c \
		srcs/sort_operations/push.c \
		srcs/sort_operations/swap.c \
		srcs/sort_operations/rotate.c \
		srcs/sort_operations/reverse.c \
		srcs/misc/ft_stacks.c \
		srcs/error_handler/ft_error.c \
		srcs/misc/ft_free_split.c \
		srcs/misc/parsing.c

OBJS = $(SRCS:.c=.o)

HEADER = $(includes/push_swap.h)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(GET_NEXT_LINE)
	make -C $(PRINTF)
	make -C $(LIBFT)
	cc $(OBJS) -L./libs/get_next_line -lget_next_line -L./libs/ft_printf -lftprintf -L./libs/libft -lft -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(PRINTF) clean
	make -C $(GET_NEXT_LINE) clean
	make -C $(LIBFT) clean
fclean: clean
	$(RM) $(NAME)
	make -C $(PRINTF) fclean
	make -C $(GET_NEXT_LINE) fclean
	make -C $(LIBFT) fclean
re: fclean all

.PHONY: all clean fclean re
