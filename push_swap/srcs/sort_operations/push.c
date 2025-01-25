/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:23:09 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/25 17:18:04 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size == 0)
		return ;
	i = a->size;
	while (i > 0)
	{
		a->numbers[i] = a->numbers[i - 1];
		i--;
	}
	a->numbers[0] = b->numbers[0];
	while (i < b->size)
	{
		b->numbers[i] = b->numbers[i + 1];
		i++;
	}
	b->size--;
	a->size++;
	a->operation_count++;
	ft_printf("pa ");
}

void	push_b(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size == 0)
		return ;
	i = b->size;
	while (i > 0)
	{
		b->numbers[i] = b->numbers[i - 1];
		i--;
	}
	b->numbers[0] = a->numbers[0];
	while (i < a->size)
	{
		a->numbers[i] = a->numbers[i + 1];
		i++;
	}
	a->size--;
	b->size++;
	a->operation_count++;
	ft_printf("pb ");
}
