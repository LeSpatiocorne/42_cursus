/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:01:28 by nidruon           #+#    #+#             */
/*   Updated: 2024/11/25 13:28:06 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	return (ft_putnbr_base_fd(nb, "0123456789", 1));
}
