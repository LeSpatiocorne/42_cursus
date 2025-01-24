/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:07:22 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/16 10:12:32 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/get_next_line/get_next_line.h"

typedef struct s_stack
{
	int	*numbers;
	int	size;
	int	capacity;
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
void			ft_algo1(t_stack *a, t_stack *b);
void			ft_free_split(char **split);
int				ft_atoi(const char *str);
int				is_sorted(t_stack *stack);
int				find_min_position(t_stack *stack);
void			print_stack(t_stack *stack, char *stack_name);
static t_stack	*init_stack(char **numbers, int count);
static t_stack	*parse_multiple_args(int argc, char **argv);
static t_stack	*parse_single_string(char *str);

#endif
