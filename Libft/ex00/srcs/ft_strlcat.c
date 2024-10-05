/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:24:10 by nidruon           #+#    #+#             */
/*   Updated: 2024/10/05 18:42:28 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && i + j < dstsize - 1)
		dst[i + j] = src[j];
	dst[i + j] = '\0';
	return (dst_len + src_len);
}
