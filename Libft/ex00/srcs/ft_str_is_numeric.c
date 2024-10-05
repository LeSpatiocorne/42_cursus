/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndruon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:22:11 by ndruon            #+#    #+#             */
/*   Updated: 2024/07/23 12:22:26 by ndruon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_str_is_numeric(char	*str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if (!(str[len] > 47 && str[len] < 58))
			return (0);
		len++;
	}
	return (1);
}
