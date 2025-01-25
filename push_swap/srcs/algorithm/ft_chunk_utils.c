/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:43:22 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/25 20:04:50 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void	normalize_stack(t_stack *stack)
{
	int	*sorted;
	int	i;
	int	j;
	int	size;

	size = stack->size;
	sorted = malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		sorted[i] = stack->numbers[i];
	sort_array(sorted, size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size && stack->numbers[i] != sorted[j])
			;
		stack->numbers[i] = j;
	}
	free(sorted);
}

int	get_chunk_size(int stack_size)
{
	if (stack_size <= 20)
		return (5);
	if (stack_size <= 100)
		return (20);
	if (stack_size <= 500)
		return (40);
	return (50);
}

int	find_next_in_chunk(t_stack *a, int chunk_start, int chunk_end)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->numbers[i] >= chunk_start && a->numbers[i] <= chunk_end)
			return (i);
		i++;
	}
	return (-1);
}

int	find_max_pos(t_stack *b)
{
	int	max;
	int	pos;
	int	i;

	max = -1;
	pos = 0;
	i = -1;
	while (++i < b->size)
	{
		if (b->numbers[i] > max)
		{
			max = b->numbers[i];
			pos = i;
		}
	}
	return (pos);
}
