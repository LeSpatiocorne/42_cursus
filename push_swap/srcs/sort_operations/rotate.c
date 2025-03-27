/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:25:13 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/25 15:20:32 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_stack(t_stack *s)
{
	int	temp;
	int	temp_orig;
	int	i;

	if (!s || s->size < 2)
		return ;
	temp = s->numbers[0];
	temp_orig = s->original_numbers[0];
	i = -1;
	while (++i < s->size - 1)
	{
		s->numbers[i] = s->numbers[i + 1];
		s->original_numbers[i] = s->original_numbers[i + 1];
	}
	s->numbers[s->size - 1] = temp;
	s->original_numbers[s->size - 1] = temp_orig;
}

void	ra(t_stack *a)
{
	rotate_stack(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate_stack(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_printf("rr\n");
}
