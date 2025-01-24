/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 08:01:11 by nidruon           #+#    #+#             */
/*   Updated: 2025/01/07 11:59:16 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_error(int error_code)
{
	if (error_code == 1)
		ft_putstr_fd("Error : Some value in the stack is not a number\n", 2);
	else if (error_code == 2)
		ft_putstr_fd("Error : The stack is empty\n", 2);
	else if (error_code == 3)
		ft_putstr_fd("Error : The stack is not sorted\n", 2);
	exit(1);
}
