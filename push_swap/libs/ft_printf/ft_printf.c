/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:30:26 by nidruon           #+#    #+#             */
/*   Updated: 2024/11/26 13:54:44 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(char c, va_list *args)
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
		return (ft_print_hex(args, c));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_print_arg(format[i + 1], &args);
			i += 2;
		}
		else
			len += write(1, &format[i++], 1);
	}
	va_end(args);
	return (len);
}
