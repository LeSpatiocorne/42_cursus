/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_numbers_from_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:32:26 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/25 16:49:04 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	process_numbers(char *line, int *temp_nums, int *count)
{
	char	**numbers;
	int		i;

	if (!line)
		return (0);
	numbers = ft_split(line, ' ');
	if (!numbers)
	{
		free(line);
		return (0);
	}
	i = 0;
	while (numbers[i])
	{
		temp_nums[*count] = ft_atoi(numbers[i]);
		(*count)++;
		i++;
	}
	ft_free_split(numbers);
	free(line);
	return (1);
}

static int	read_file_content(int fd, int *temp_nums, int *count)
{
	char	*line;

	*count = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		if (!process_numbers(line, temp_nums, count))
		{
			free(line);
			return (0);
		}
		line = get_next_line(fd);
	}
	return (1);
}

static t_stack	*init_final_stack(int count)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->numbers = malloc(sizeof(int) * count);
	if (!stack->numbers)
	{
		free(stack);
		return (NULL);
	}
	stack->size = count;
	stack->operation_count = 0;
	return (stack);
}

static t_stack	*create_final_stack(int *temp_numbers, int count)
{
	t_stack	*stack;
	int		i;

	if (count == 0)
	{
		free(temp_numbers);
		return (NULL);
	}
	stack = init_final_stack(count);
	if (!stack)
	{
		free(temp_numbers);
		return (NULL);
	}
	i = -1;
	while (++i < count)
		stack->numbers[i] = temp_numbers[i];
	free(temp_numbers);
	return (stack);
}

t_stack	*read_numbers_from_file(char *file)
{
	int		fd;
	int		*temp_nums;
	int		count;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	temp_nums = malloc(sizeof(int) * 10000);
	if (!temp_nums)
	{
		close(fd);
		return (NULL);
	}
	if (!read_file_content(fd, temp_nums, &count))
	{
		free(temp_nums);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (create_final_stack(temp_nums, count));
}
