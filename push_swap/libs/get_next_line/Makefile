NAME		= libget_next_line.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

LIBFT_PATH	= ../libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRCS		= get_next_line.c
OBJS		= $(SRCS:.c=.o)

HEADER		= get_next_line.h

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH) >/dev/null

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS) >/dev/null
	@echo "\033[35m🎯 Archive created: $(NAME)\033[0m"

%.o: %.c $(HEADER)
	@echo "\033[32m🛠️ Compiling $<\033[0m"
	@$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH) clean >/dev/null
	@echo "🧹 Object files cleaned"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean >/dev/null
	@echo "🧹 Archive removed"

re: fclean all

.PHONY: all clean fclean re
