/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:11:25 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/25 15:49:26 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_duplicate_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_numbers_validity(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		if (!ft_isnumber(numbers[i]))
			return (1);
		j = i + 1;
		while (numbers[j])
		{
			if (ft_strcmp(numbers[i], numbers[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_duplicate_inarg(char *arg)
{
	char	**numbers;
	int		i;
	int		result;

	if (!arg || arg[0] == '\0')
		return (1);
	numbers = ft_split(arg, ' ');
	if (!numbers)
		return (1);
	result = check_numbers_validity(numbers);
	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
	return (result);
}
