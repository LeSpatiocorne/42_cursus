/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:25:13 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/25 17:48:41 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->numbers[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->numbers[i] = a->numbers[i + 1];
		i++;
	}
	a->numbers[a->size - 1] = temp;
	a->operation_count++;
	ft_printf("ra ");
}

void	rotate_b(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->numbers[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->numbers[i] = b->numbers[i + 1];
		i++;
	}
	b->numbers[b->size - 1] = temp;
	b->operation_count++;
	ft_printf("rb ");
}

void	rotate_r(t_stack *a, t_stack *b)
{
	rotate_a(a);
	rotate_b(b);
	a->operation_count--;
	b->operation_count--;
	a->operation_count++;
	ft_printf("rr ");
}
