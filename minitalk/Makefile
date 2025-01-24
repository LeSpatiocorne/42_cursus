CC = gcc
CFLAGS = -Wall -Wextra -Werror

all:
	make -C ./ft_printf
	@if [ ! -f client ]; then \
		$(CC) $(CFLAGS) client.c -o client ./ft_printf/libftprintf.a; \
	fi
	@if [ ! -f server ]; then \
		$(CC) $(CFLAGS) server.c -o server ./ft_printf/libftprintf.a; \
	fi

clean:
	rm -f client.o server.o client_bonus.o server_bonus.o
	make clean -C ./ft_printf

fclean: clean
	rm -f client server client_bonus server_bonus
	make fclean -C ./ft_printf

bonus:
	make -C ./ft_printf
	@if [ ! -f client_bonus ]; then \
		$(CC) $(CFLAGS) client_bonus.c -o client_bonus ./ft_printf/libftprintf.a; \
	fi
	@if [ ! -f server_bonus ]; then \
		$(CC) $(CFLAGS) server_bonus.c -o server_bonus ./ft_printf/libftprintf.a; \
	fi

re: fclean all

.PHONY: all clean fclean re
