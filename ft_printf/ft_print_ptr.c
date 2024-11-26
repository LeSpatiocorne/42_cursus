/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:57:26 by nidruon           #+#    #+#             */
/*   Updated: 2024/11/26 13:42:13 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_print_hex_ptr(unsigned long num)
{
	int	len;

	len = 0;
	if (num >= 16)
	{
		len += ft_print_hex_ptr(num / 16);
		len += ft_print_hex_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
		len++;
	}
	return (len);
}

int	ft_print_ptr(va_list *args)
{
	void	*ptr;

	ptr = va_arg(*args, void *);
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_print_hex_ptr((unsigned long)ptr));
}
