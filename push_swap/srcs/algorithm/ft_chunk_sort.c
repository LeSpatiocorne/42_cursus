/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:42:07 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/25 19:45:09 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort_by_chunks(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunk_start;
	int	num_chunks;
	int	i;

	normalize_stack(a);
	chunk_size = get_chunk_size(a->size);
	num_chunks = (a->size + chunk_size - 1) / chunk_size;
	i = 0;
	while (i < num_chunks)
	{
		chunk_start = i * chunk_size;
		push_chunk_to_b(a, b, chunk_start,
			chunk_start + chunk_size - 1);
		i++;
	}
	push_back_to_a(a, b);
}
