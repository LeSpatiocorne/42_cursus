/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:58:52 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/25 15:22:17 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_stack(t_stack *stack)
{
	int	temp;
	int	temp_orig;

	if (!stack || stack->size < 2)
		return ;
	temp = stack->numbers[0];
	temp_orig = stack->original_numbers[0];
	stack->numbers[0] = stack->numbers[1];
	stack->original_numbers[0] = stack->original_numbers[1];
	stack->numbers[1] = temp;
	stack->original_numbers[1] = temp_orig;
}

void	sa(t_stack *a)
{
	swap_stack(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap_stack(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	ft_printf("ss\n");
}
