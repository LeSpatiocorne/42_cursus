/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:58:05 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/25 17:08:02 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_min(t_stack *stack)
{
	int	i;
	int	min_pos;
	int	min;

	i = 0;
	min_pos = 0;
	min = stack->numbers[0];
	while (i < stack->size)
	{
		if (stack->numbers[i] < min)
		{
			min = stack->numbers[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_pos;

	min_pos = find_min(a);
	while (min_pos > 0)
	{
		rotate_a(a);
		min_pos--;
	}
	push_b(a, b);
}

void	ft_sort_by_selection(t_stack *a, t_stack *b)
{
	while (a->size > 0)
		push_min_to_b(a, b);
	while (b->size > 0)
		push_a(a, b);
}
