/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:07:22 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/27 15:31:33 by nidruon          ###   ########.fr       */
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
	int	*original_numbers;
	int	size;
	int	capacity;
}	t_stack;

void			ft_error(int error_code);
int				ft_duplicate_arg(int ac, char **av);
int				ft_duplicate_inarg(char *arg);
t_stack			*init_stack(char **numbers, int count);
t_stack			*init_stack_b(t_stack *stack_a);
void			ft_free_split(char **split);
int				ft_atoi(const char *str);
t_stack			*parse_multiple_args(int argc, char **argv);
t_stack			*parse_single_string(char *str);
void			free_stacks(t_stack *stack_a, t_stack *stack_b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
void			sort_three(t_stack *stack);
void			sort_four(t_stack *a, t_stack *b);
void			sort_five(t_stack *stack_a, t_stack *stack_b);
void			turkish_sort(t_stack *stack_a, t_stack *stack_b);
void			push_back_sorted(t_stack *a, t_stack *b);
int				is_sorted(t_stack *stack);
int				get_index_in_stack(t_stack *stack, int value);
int				find_min_position(t_stack *stack);
int				find_max_position(t_stack *stack);
int				find_closest_in_chunk(t_stack *stack, int min_val, int max_val);
void			push_smallest_to_b(t_stack *a, t_stack *b);

#endif
