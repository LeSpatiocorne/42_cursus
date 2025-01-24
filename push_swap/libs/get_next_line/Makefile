NAME = libget_next_line.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Ajout du chemin vers libft
LIBFT_PATH = ../libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = get_next_line.c

OBJS = $(SRCS:.c=.o)

HEADER = get_next_line.h

all: $(NAME)

# Règle pour compiler libft d'abord
$(LIBFT):
	make -C $(LIBFT_PATH)

# Modification pour inclure libft
$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
