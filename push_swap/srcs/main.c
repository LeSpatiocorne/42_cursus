/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:17:12 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/25 15:55:16 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc == 2)
	{
		stack_a = parse_single_string(argv[1]);
	}
	else
		stack_a = parse_multiple_args(argc, argv);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		ft_error(0);
	if (argc == 2)
		if (ft_duplicate_inarg(argv[1]))
			return (1);
	if (argc > 2)
		if (ft_duplicate_arg(argc, argv))
			return (1);
	stack_a = parse_input(argc, argv);
	if (!stack_a)
		ft_error(1);
	stack_b = init_stack_b(stack_a);
	if (!stack_b)
	{
		free_stacks(stack_a, NULL);
		return (1);
	}
	if (!is_sorted(stack_a))
		turkish_sort(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
