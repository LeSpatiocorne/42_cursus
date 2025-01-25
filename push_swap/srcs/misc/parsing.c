/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:57:35 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/25 16:09:03 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*init_stack(char **numbers, int count)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_free_split(numbers);
		return (NULL);
	}
	stack->operation_count = 0;
	stack->capacity = count;
	stack->numbers = malloc(sizeof(int) * count);
	if (!stack->numbers)
	{
		free(stack);
		ft_free_split(numbers);
		return (NULL);
	}
	stack->size = count;
	return (stack);
}

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

	i = 0;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->capacity = argc - 1;
	stack->operation_count = 0;
	stack->numbers = malloc(sizeof(int) * (argc - 1));
	if (!stack->numbers)
	{
		free(stack);
		return (NULL);
	}
	stack->size = argc - 1;
	while (i < argc - 1)
	{
		stack->numbers[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (stack);
}
