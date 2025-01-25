/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:27:49 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/25 16:52:48 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_stack(t_stack *stack, char *stack_name)
{
	int	i;

	i = 0;
	ft_printf("\n%s contient %d nombres:\n", stack_name, stack->size);
	while (i < stack->size)
	{
		ft_printf("%d ", stack->numbers[i]);
		i++;
	}
	ft_printf("\n");
}
