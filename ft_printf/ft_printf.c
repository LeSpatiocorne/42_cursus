/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:30:26 by nidruon           #+#    #+#             */
/*   Updated: 2024/11/25 13:08:13 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(args));
	if (c == 's')
		return (ft_print_str(args));
	if (c == 'p')
		return (ft_print_ptr(args));
	if (c == 'd' || c == 'i')
		return (ft_print_int(args));
	if (c == 'u')
		return (ft_print_unsigned(args));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(args));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (format[i])
		i += ft_print_arg(format[i], args);
	va_end(args);
	return (i);
}

/*
int	main(void)
{
	ft_printf("Hello, World!\n");
	return (0);
}
*/
