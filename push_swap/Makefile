NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -c -g
RM			= rm -f

PRINTF		= ./libs/ft_printf
GET_NEXT_LINE	= ./libs/get_next_line
LIBFT		= ./libs/libft

SRCS		= srcs/main.c \
			  srcs/sort_operations/push.c \
			  srcs/sort_operations/swap.c \
			  srcs/sort_operations/rotate.c \
			  srcs/sort_operations/reverse.c \
			  srcs/error_handler/ft_error.c \
			  srcs/error_handler/ft_duplicate_arg.c \
			  srcs/misc/parsing.c \
			  srcs/misc/stack.c \
			  srcs/misc/free_misc.c \
			  srcs/algorithm/sort_three.c \
			  srcs/algorithm/sort_four.c \
			  srcs/algorithm/sort_five.c \
			  srcs/algorithm/sort_turkish.c \
			  srcs/algorithm/sort_utils.c \
			  srcs/algorithm/sort_utils_extra.c

OBJS_DIR	= objs/
OBJS		= $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
HEADER		= includes/push_swap.h

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@make -C $(GET_NEXT_LINE) >/dev/null
	@make -C $(PRINTF) >/dev/null
	@make -C $(LIBFT) >/dev/null
	@$(CC) $(OBJS) \
		-L$(GET_NEXT_LINE) -lget_next_line \
		-L$(PRINTF) -lftprintf \
		-L$(LIBFT) -lft \
		-o $(NAME)
	@echo "\033[32m✅ Binary created: $(NAME)\033[0m"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: srcs/%.c $(HEADER)
	@echo "🛠️ Compiling $<"
	@$(CC) $(CFLAGS) -I includes -c $< -o $@

$(OBJS_DIR)%.o: srcs/sort_operations/%.c $(HEADER)
	@echo "🛠️ Compiling $<"
	@$(CC) $(CFLAGS) -I includes -c $< -o $@

$(OBJS_DIR)%.o: srcs/error_handler/%.c $(HEADER)
	@echo "🛠️ Compiling $<"
	@$(CC) $(CFLAGS) -I includes -c $< -o $@

$(OBJS_DIR)%.o: srcs/misc/%.c $(HEADER)
	@echo "🛠️ Compiling $<"
	@$(CC) $(CFLAGS) -I includes -c $< -o $@

$(OBJS_DIR)%.o: srcs/algorithm/%.c $(HEADER)
	@echo "🛠️ Compiling $<"
	@$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	@$(RM) -r $(OBJS_DIR)
	@make -C $(PRINTF) clean >/dev/null
	@make -C $(GET_NEXT_LINE) clean >/dev/null
	@make -C $(LIBFT) clean >/dev/null
	@echo "🧹 Object files cleaned"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(PRINTF) fclean >/dev/null
	@make -C $(GET_NEXT_LINE) fclean >/dev/null
	@make -C $(LIBFT) fclean >/dev/null
	@echo "🧹 Binary removed"

re: fclean all

.PHONY: all clean fclean re
