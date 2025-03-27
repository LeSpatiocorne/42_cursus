/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:23:09 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/27 14:48:55 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_stack(t_stack *dst, t_stack *src)
{
	int	i;

	if (!dst || !src || src->size == 0)
		return ;
	i = dst->size;
	while (i > 0)
	{
		dst->numbers[i] = dst->numbers[i - 1];
		dst->original_numbers[i] = dst->original_numbers[i - 1];
		i--;
	}
	dst->numbers[0] = src->numbers[0];
	dst->original_numbers[0] = src->original_numbers[0];
	dst->size++;
	i = 0;
	while (i < src->size - 1)
	{
		src->numbers[i] = src->numbers[i + 1];
		src->original_numbers[i] = src->original_numbers[i + 1];
		i++;
	}
	src->size--;
}

void	pa(t_stack *a, t_stack *b)
{
	push_stack(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push_stack(b, a);
	ft_printf("pb\n");
}
