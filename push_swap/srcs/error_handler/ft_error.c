/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 08:01:11 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/21 15:47:34 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_error(int error_code)
{
	if (error_code == 0)
		ft_putstr_fd("Error : Incorrect ammount of arguments provided\n", 2);
	else if (error_code == 1)
		ft_putstr_fd("Error : The stack is empty\n", 2);
	exit(1);
}
