/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:25:34 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/25 15:20:57 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate_stack(t_stack *s)
{
	int	temp;
	int	temp_orig;
	int	i;

	if (!s || s->size < 2)
		return ;
	temp = s->numbers[s->size - 1];
	temp_orig = s->original_numbers[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->numbers[i] = s->numbers[i - 1];
		s->original_numbers[i] = s->original_numbers[i - 1];
		i--;
	}
	s->numbers[0] = temp;
	s->original_numbers[0] = temp_orig;
}

void	rra(t_stack *a)
{
	reverse_rotate_stack(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotate_stack(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	ft_printf("rrr\n");
}
