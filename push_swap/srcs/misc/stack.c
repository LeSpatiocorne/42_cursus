/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:53:04 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/25 15:59:55 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*create_empty_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->numbers = malloc(sizeof(int) * capacity);
	if (!stack->numbers)
		return (free(stack), NULL);
	stack->original_numbers = malloc(sizeof(int) * capacity);
	if (!stack->original_numbers)
	{
		free(stack->numbers);
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

t_stack	*init_stack_b(t_stack *stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = create_empty_stack(stack_a->capacity);
	if (!stack_b)
		return (NULL);
	i = -1;
	while (++i < stack_b->capacity)
		stack_b->original_numbers[i] = 0;
	return (stack_b);
}

t_stack	*init_stack(char **numbers, int count)
{
	t_stack	*stack;
	int		i;

	stack = create_empty_stack(count);
	if (!stack)
	{
		ft_free_split(numbers);
		return (NULL);
	}
	stack->size = count;
	i = -1;
	while (++i < count)
	{
		stack->numbers[i] = ft_atoi(numbers[i]);
		stack->original_numbers[i] = stack->numbers[i];
	}
	return (stack);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		if (stack_a->numbers)
			free(stack_a->numbers);
		if (stack_a->original_numbers)
			free(stack_a->original_numbers);
		free(stack_a);
	}
	if (stack_b)
	{
		if (stack_b->numbers)
			free(stack_b->numbers);
		if (stack_b->original_numbers)
			free(stack_b->original_numbers);
		free(stack_b);
	}
}
