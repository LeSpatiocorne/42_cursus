NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs

SRCS		= ft_atoi.c \
			  ft_bzero.c \
			  ft_memset.c \
			  ft_memcpy.c \
			  ft_memccpy.c \
			  ft_memmove.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strlen.c \
			  ft_strcmp.c \
			  ft_strncmp.c \
			  ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isnumber.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_strcpy.c \
			  ft_strncpy.c \
			  ft_strdup.c \
			  ft_strcat.c \
			  ft_strncat.c \
			  ft_strstr.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strnstr.c \
			  ft_strlcat.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_split.c \
			  ft_itoa.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_strmapi.c \
			  ft_striteri.c \
			  ft_calloc.c \
			  ft_strlcpy.c \
			  ft_putnbr_base_fd.c

OBJS_DIR	= objs/
OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(AR) $(NAME) $(OBJS) >/dev/null
	@echo "\033[35m🎯 Archive created: $(NAME)\033[0m"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: %.c
	@echo "\033[32m🛠️ Compiling $<\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "🧹 Object files cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "🧹 Archive removed"

re: fclean all

.PHONY: all clean fclean re
