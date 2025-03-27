/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turkish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:43:22 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/27 15:19:03 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_closest_chunk(t_stack *a, t_stack *b, int min, int max)
{
	int	pos;
	int	i;

	pos = find_closest_in_chunk(a, min, max);
	if (pos == -1)
		return ;
	if (pos <= a->size / 2)
	{
		i = 0;
		while (i++ < pos)
			ra(a);
	}
	else
	{
		i = 0;
		while (i++ < a->size - pos)
			rra(a);
	}
	pb(a, b);
}

static void	sort_chunks(t_stack *a, t_stack *b, int chunk)
{
	int	min;
	int	max;
	int	start;
	int	end;

	min = a->numbers[find_min_position(a)];
	max = a->numbers[find_max_position(a)];
	start = min;
	end = start + chunk;
	while (start <= max)
	{
		if (end > max)
			end = max;
		while (find_closest_in_chunk(a, start, end) != -1)
			push_closest_chunk(a, b, start, end);
		start += chunk;
		end += chunk;
	}
}

void	push_back_sorted(t_stack *a, t_stack *b)
{
	int	max_pos;
	int	i;

	while (b->size > 0)
	{
		max_pos = find_max_position(b);
		if (max_pos == 0)
			pa(a, b);
		else if (max_pos <= b->size / 2)
		{
			i = 0;
			while (i++ < max_pos)
				rb(b);
			pa(a, b);
		}
		else
		{
			i = 0;
			while (i++ < b->size - max_pos)
				rrb(b);
			pa(a, b);
		}
	}
}

void	turkish_sort(t_stack *a, t_stack *b)
{
	int	chunk;

	if (!a || !b)
		return ;
	if (a->size <= 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
	{
		if (a->size <= 100)
			chunk = a->size / 6;
		else
			chunk = a->size / 11;
		sort_chunks(a, b, chunk);
		if (a->size == 3)
			sort_three(a);
		else if (a->size == 2 && a->numbers[0] > a->numbers[1])
			sa(a);
		push_back_sorted(a, b);
	}
}
