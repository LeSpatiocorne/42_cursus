/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:59:19 by nidruon           #+#    #+#             */
/*   Updated: 2024/11/25 13:28:15 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_fd(unsigned int nb, char *base, int fd)
{
	int	len;

	len = ft_strlen(base);
	if (nb >= len)
		ft_putnbr_base_fd(nb / len, base, fd);
	write(fd, &base[nb % len], 1);
	return (1);
}
