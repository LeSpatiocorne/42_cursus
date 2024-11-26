/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:42:23 by nidruon           #+#    #+#             */
/*   Updated: 2024/11/26 13:42:23 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
		return (write(1, "(null)", 6));
	if (str[0] == '\0')
		return (0);
	return (write(1, str, ft_strlen(str)));
}
