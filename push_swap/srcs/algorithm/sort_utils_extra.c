/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:54:59 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/27 14:41:59 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	middle;

	if (!a || !b || a->size < 1)
		return ;
	min_pos = find_min_position(a);
	middle = a->size / 2;
	if (min_pos <= middle)
		while (min_pos-- > 0)
			ra(a);
	else
		while (min_pos++ < a->size)
			rra(a);
	pb(a, b);
}
