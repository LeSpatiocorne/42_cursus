/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:27:49 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/14 09:42:29 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*create_stack(int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->numbers = (int *)malloc(sizeof(int) * capacity);
	if (!stack->numbers)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

void	init_stacks(t_stack **a, t_stack **b, int capacity)
{
	*a = create_stack(capacity);
	*b = create_stack(capacity);
	if (!*a || !*b)
	{
		if (*a)
		{
			free((*a)->numbers);
			free(*a);
		}
		if (*b)
		{
			free((*b)->numbers);
			free(*b);
		}
		exit(1);
	}
}

void	print_stack(t_stack *stack, char *stack_name)
{
	int	i;

	i = 0;
	ft_printf("\n%s contient %d nombres:\n", stack_name, stack->size);
	while (i < stack->size)
	{
		ft_printf("%d ", stack->numbers[i]);
		i++;
	}
	ft_printf("\n");
}
