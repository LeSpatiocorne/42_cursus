/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:57:35 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/25 15:53:32 by nidruon          ###   ########.fr       */
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
	t_stack	*stack;
	int		i;

	i = -1;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->capacity = argc - 1;
	stack->numbers = malloc(sizeof(int) * (argc - 1));
	if (!stack->numbers)
	{
		free(stack);
		return (NULL);
	}
	stack->original_numbers = malloc(sizeof(int) * (argc - 1));
	if (!stack->original_numbers)
	{
		free(stack->numbers);
		free(stack);
		return (NULL);
	}
	stack->size = argc - 1;
	while (++i < argc - 1)
	{
		stack->numbers[i] = ft_atoi(argv[i + 1]);
		stack->original_numbers[i] = stack->numbers[i];
	}
	return (stack);
}
