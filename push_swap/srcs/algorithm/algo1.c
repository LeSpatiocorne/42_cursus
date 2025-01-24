/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:22:34 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/13 11:22:58 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min_position(t_stack *stack)
{
	int	i;
	int	min;
	int	min_pos;

	i = 0;
	min = stack->numbers[0];
	min_pos = 0;
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

void	ft_algo1(t_stack *a, t_stack *b)
{
	int	min_pos;

	while (a->size > 0 && !is_sorted(a))
	{
		min_pos = find_min_position(a);
		if (min_pos == 0)
			push_b(a, b);
		else if (min_pos <= a->size / 2)
			rotate_a(a);
		else
			reverse_ra(a);
	}
	while (b->size > 0)
		push_a(a, b);
}
