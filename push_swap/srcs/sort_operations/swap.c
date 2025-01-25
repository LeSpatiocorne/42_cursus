/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:58:52 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/25 17:48:38 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->numbers[0];
	a->numbers[0] = a->numbers[1];
	a->numbers[1] = temp;
	a->operation_count++;
	ft_printf("sa ");
}

void	swap_b(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->numbers[0];
	b->numbers[0] = b->numbers[1];
	b->numbers[1] = temp;
	b->operation_count++;
	ft_printf("sb ");
}

void	swap_s(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
	a->operation_count--;
	b->operation_count--;
	a->operation_count++;
	ft_printf("ss ");
}
