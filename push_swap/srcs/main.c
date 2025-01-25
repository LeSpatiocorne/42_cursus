/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:17:12 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/25 20:12:29 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->numbers[i] > stack->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		if (stack_a->numbers)
			free(stack_a->numbers);
		free(stack_a);
	}
	if (stack_b)
	{
		if (stack_b->numbers)
			free(stack_b->numbers);
		free(stack_b);
	}
}

static t_stack	*init_stack_b(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		return (NULL);
	stack_b->numbers = malloc(sizeof(int) * stack_a->size);
	if (!stack_b->numbers)
	{
		free(stack_b);
		return (NULL);
	}
	stack_b->size = 0;
	return (stack_b);
}

static t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc == 2)
	{
		if (ft_strchr(argv[1], ' '))
			stack_a = parse_single_string(argv[1]);
		else
			stack_a = read_numbers_from_file(argv[1]);
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
		ft_sort_by_chunks(stack_a, stack_b);
	ft_printf("\nRésultat du tri:\n");
	print_stack(stack_a, "Stack A");
	ft_printf("Nombre d'opérations: %d\n", stack_a->operation_count);
	free_stacks(stack_a, stack_b);
	return (0);
}
