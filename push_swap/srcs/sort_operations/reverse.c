/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:25:34 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/25 17:18:17 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_ra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->numbers[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->numbers[i] = a->numbers[i - 1];
		i--;
	}
	a->numbers[0] = temp;
	a->operation_count++;
	ft_printf("rra ");
}

void	reverse_rb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->numbers[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->numbers[i] = b->numbers[i - 1];
		i--;
	}
	b->numbers[0] = temp;
	write(1, "rrb ", 4);
}

void	reverse_rr(t_stack *a, t_stack *b)
{
	reverse_ra(a);
	reverse_rb(b);
	ft_printf("rrr ");
}
