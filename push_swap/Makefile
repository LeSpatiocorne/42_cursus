NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar rcs
RM = rm -f

PRINTF = ./libs/ft_printf
GET_NEXT_LINE = ./libs/get_next_line
SRCS = srcs/main.c

OBJS = $(SRCS:.c=.o)

HEADER = $(includes/push_swap.h)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTF)
	make -C $(GET_NEXT_LINE)
	$(CC) $(OBJS) -L$(PRINTF) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(PRINTF) clean
	make -C $(GET_NEXT_LINE) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(PRINTF) fclean
	make -C $(GET_NEXT_LINE) fclean

re: fclean all

.PHONY: all clean fclean re
