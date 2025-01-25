/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:43:28 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/25 20:04:40 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_chunk_to_b(t_stack *a, t_stack *b, int c_start, int c_end)
{
	int	pos;
	int	mid;
	int	rot_count;

	pos = find_next_in_chunk(a, c_start, c_end);
	while (pos != -1)
	{
		mid = a->size / 2;
		rot_count = pos + 1;
		if (pos <= mid)
		{
			while (rot_count--, rot_count > 0)
				rotate_a(a);
		}
		else
		{
			rot_count = a->size - pos + 1;
			while (rot_count--, rot_count > 0)
				reverse_ra(a);
		}
		push_b(a, b);
		pos = find_next_in_chunk(a, c_start, c_end);
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	pos;
	int	rot_count;

	while (b->size > 0)
	{
		pos = find_max_pos(b);
		rot_count = pos;
		if (pos <= b->size / 2)
			while (rot_count--)
				rotate_b(b);
		else
		{
			rot_count = b->size - pos;
			while (rot_count--)
				reverse_rb(b);
		}
		push_a(a, b);
	}
}
