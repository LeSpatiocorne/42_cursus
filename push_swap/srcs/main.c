/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:17:12 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/06 09:52:43 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_read_file(char *file)
{
	int		fd;
	char	*line;

	fd = open("test1", O_RDONLY);
	line = get_next_line(fd);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc < 2)
		ft_read_file("test1");
	if (argc == 2)
		while (argv[1][i])
			if (ft_isdigit(argv[1][i]))
				//input to the sorting logic
			i++;
	if (argc > 2)
		while (argv[i])
			if (ft_isdigit(argv[i]))
				//input to the sorting logic
			i++;
}

