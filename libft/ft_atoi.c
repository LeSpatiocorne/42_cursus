/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:24:55 by ndruon            #+#    #+#             */
/*   Updated: 2024/11/06 17:36:47 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	number;

	i = 0;
	number = 0;
	nb = 1;
	while (!(str[i] > 32 && str[i] < 127))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nb = -nb;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
		number = number * 10 + str[i++] - 48;
	return (number * nb);
}
