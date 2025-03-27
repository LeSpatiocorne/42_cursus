/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:43:22 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/25 15:39:14 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_index_in_stack(t_stack *stack, int value)
{
	int	i;

	i = 0;
	if (!stack || stack->size < 1)
		return (-1);
	while (i < stack->size)
	{
		if (stack->numbers[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	find_min_position(t_stack *stack)
{
	int	i;
	int	min;
	int	min_pos;

	if (!stack || stack->size < 1)
		return (-1);
	min = stack->numbers[0];
	min_pos = 0;
	i = 1;
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

int	find_max_position(t_stack *stack)
{
	int	i;
	int	max;
	int	max_pos;

	if (!stack || stack->size < 1)
		return (-1);
	max = stack->numbers[0];
	max_pos = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->numbers[i] > max)
		{
			max = stack->numbers[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || stack->size < 2)
		return (1);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->numbers[i] > stack->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	find_closest_in_chunk(t_stack *stack, int min_val, int max_val)
{
	int	i;
	int	closest_pos;
	int	found;

	if (!stack || stack->size < 1)
		return (-1);
	closest_pos = -1;
	found = 0;
	i = 0;
	while (i < stack->size && !found)
	{
		if (stack->numbers[i] >= min_val && stack->numbers[i] <= max_val)
		{
			closest_pos = i;
			found = 1;
		}
		i++;
	}
	return (closest_pos);
}
