/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:17:12 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/14 09:40:13 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *read_numbers_from_file(char *file)
{
	int		fd;
	char	*line;
	t_stack	*stack;
	int		*temp_numbers;
	int		capacity = 100;
	int		count = 0;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Cannot open file\n");
		return NULL;
	}
	temp_numbers = malloc(sizeof(int) * capacity);
	if (!temp_numbers)
	{
		close(fd);
		return NULL;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		char **numbers = ft_split(line, ' ');
		if (!numbers)
		{
			free(temp_numbers);
			free(line);
			close(fd);
			return NULL;
		}
		for (int i = 0; numbers[i]; i++)
		{
			if (count >= capacity)
			{
				capacity *= 2;
				int *new_temp = realloc(temp_numbers, sizeof(int) * capacity);
				if (!new_temp)
				{
					free(temp_numbers);
					ft_free_split(numbers);
					free(line);
					close(fd);
					return NULL;
				}
				temp_numbers = new_temp;
			}
			temp_numbers[count++] = ft_atoi(numbers[i]);
		}
		ft_free_split(numbers);
		free(line);
	}
	close(fd);
	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		free(temp_numbers);
		return NULL;
	}
	stack->numbers = malloc(sizeof(int) * count);
	if (!stack->numbers)
	{
		free(temp_numbers);
		free(stack);
		return NULL;
	}
	for (int i = 0; i < count; i++)
		stack->numbers[i] = temp_numbers[i];
	stack->size = count;

	free(temp_numbers);
	return stack;
}

int is_sorted(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->numbers[i] > stack->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (argc == 2)
	{
		if (ft_strchr(argv[1], ' '))
			stack_a = parse_single_string(argv[1]);
		else
			stack_a = read_numbers_from_file(argv[1]);
	}
	else
		stack_a = parse_multiple_args(argc, argv);
	if (!stack_a)
	{
		ft_printf("Error\n");
		return (1);
	}
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
	{
		free(stack_a->numbers);
		free(stack_a);
		return (1);
	}
	stack_b->numbers = malloc(sizeof(int) * stack_a->size);
	if (!stack_b->numbers)
	{
		free(stack_a->numbers);
		free(stack_a);
		free(stack_b);
		return (1);
	}
	stack_b->size = 0;
	ft_printf("Debug: Programme démarré avec %d nombres\n", stack_a->size);
	if (!is_sorted(stack_a))
	{
		ft_algo1(stack_a, stack_b);
	}
	ft_printf("\nRésultat du tri:");
	print_stack(stack_a, "Stack A");
	free(stack_a->numbers);
	free(stack_a);
	free(stack_b->numbers);
	free(stack_b);
	return (0);
}
