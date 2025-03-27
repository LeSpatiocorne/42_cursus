/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 03:03:19 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/24 23:01:41 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_three_elements(t_stack *stack, int a, int b, int c)
{
	if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a > b && b < c && a < c)
		sa(stack);
	else if (a < b && b > c && a > c)
		rra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
}

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || stack->size < 2)
		return ;
	if (stack->size == 2)
	{
		if (stack->numbers[0] > stack->numbers[1])
			sa(stack);
		return ;
	}
	a = stack->numbers[0];
	b = stack->numbers[1];
	c = stack->numbers[2];
	sort_three_elements(stack, a, b, c);
}
