/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:52:20 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/27 15:09:58 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_four(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->numbers[0] > a->numbers[1])
			sa(a);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	push_smallest_to_b(a, b);
	sort_three(a);
	pa(a, b);
}
