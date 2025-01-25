/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:03:26 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/25 14:59:09 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	clean_up(int *numbers, char **split_nums, char *line, int fd)
{
	if (numbers)
		free(numbers);
	if (split_nums)
		ft_free_split(split_nums);
	if (line)
		free(line);
	if (fd != -1)
		close(fd);
}
