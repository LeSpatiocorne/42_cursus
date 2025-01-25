/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:07:22 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/25 17:20:40 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/get_next_line/get_next_line.h"
# include <string.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*numbers;
	int	size;
	int	capacity;
	int	operation_count;
}	t_stack;

void			ft_error(int error_code);
t_stack			*read_numbers_from_file(char *file);
void			push_a(t_stack *a, t_stack *b);
void			push_b(t_stack *a, t_stack *b);
void			swap_a(t_stack *a);
void			swap_b(t_stack *b);
void			swap_s(t_stack *a, t_stack *b);
void			rotate_a(t_stack *a);
void			rotate_b(t_stack *b);
void			rotate_r(t_stack *a, t_stack *b);
void			reverse_ra(t_stack *a);
void			reverse_rb(t_stack *b);
void			reverse_rr(t_stack *a, t_stack *b);
void			ft_free_split(char **split);
int				ft_atoi(const char *str);
void			print_stack(t_stack *stack, char *stack_name);
t_stack			*init_stack(char **numbers, int count);
t_stack			*parse_multiple_args(int argc, char **argv);
t_stack			*parse_single_string(char *str);
t_stack			*read_numbers_from_file(char *file);
void			clean_up(int *numbers, char **split_nums, char *line, int fd);
void			ft_error(int error_code);
void			ft_sort_by_selection(t_stack *a, t_stack *b);

#endif
