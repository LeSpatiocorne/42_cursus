/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:03:19 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/26 15:56:19 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_five(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->numbers[0] > a->numbers[1])
			sa(a);
		return ;
	}
	while (a->size > 3)
		push_smallest_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
