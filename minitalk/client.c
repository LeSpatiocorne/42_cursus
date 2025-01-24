/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:35:05 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/24 18:18:22 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_sync;

static void	signal_counter(int signum)
{
	if (signum == SIGUSR1)
		g_sync = 1;
	else
		exit(0);
}

static void	send_bit(int pid, int bit)
{
	int	signal_to_send;

	g_sync = 0;
	if (bit)
		signal_to_send = SIGUSR1;
	else
		signal_to_send = SIGUSR2;
	if (kill(pid, signal_to_send) == -1)
		exit(1);
	while (!g_sync)
		usleep(100);
}

void	send_char(int pid, char c)
{
	int	bit_position;

	bit_position = 0;
	while (bit_position < 8)
	{
		send_bit(pid, (c & (1 << bit_position)) != 0);
		bit_position++;
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sigaction;

	if (argc != 3)
		return (ft_printf("Usage: ./client <pid> <message>\n"));
	s_sigaction.sa_handler = signal_counter;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	if (ft_atoi(argv[1]) <= 0)
		return (ft_printf("Invalid PID\n"));
	ft_printf("Sending message: %s\n", argv[2]);
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
