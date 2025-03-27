NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_printf.c \
			  ft_print_char.c \
			  ft_print_str.c \
			  ft_print_ptr.c \
			  ft_print_int.c \
			  ft_print_unsigned.c \
			  ft_print_hex.c

OBJS_DIR	= objs/
OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

$(NAME): $(OBJS_DIR) $(OBJS)
	@make -C ../libft
	@cp ../libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJS) >/dev/null
	@echo "\033[35m🎯 Archive created: $(NAME)\033[0m"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: %.c
	@echo "\033[32m🛠️ Compiling $<\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "🧹 Objects removed"
	@make clean -C ../libft >/dev/null

fclean: clean
	@rm -f $(NAME)
	@echo "🧹 Archive removed"
	@make fclean -C ../libft >/dev/null

re: fclean all

.PHONY: all clean fclean re
