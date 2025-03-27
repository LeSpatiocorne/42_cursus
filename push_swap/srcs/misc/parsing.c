/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:57:35 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/27 15:31:09 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*parse_single_string(char *str)
{
	t_stack	*stack;
	char	**numbers;
	int		count;
	int		i;

	count = 0;
	numbers = ft_split(str, ' ');
	if (!numbers)
		return (NULL);
	while (numbers[count])
		count++;
	stack = init_stack(numbers, count);
	if (!stack)
	{
		ft_free_split(numbers);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		stack->numbers[i] = ft_atoi(numbers[i]);
		i++;
	}
	ft_free_split(numbers);
	return (stack);
}

t_stack	*parse_multiple_args(int argc, char **argv)
{
	return (init_stack(argv + 1, argc - 1));
}
