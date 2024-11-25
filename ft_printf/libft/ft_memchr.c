/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:53:01 by nidruon           #+#    #+#             */
/*   Updated: 2024/11/08 12:01:45 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (((void *)s) + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main(void)
{
    // Test 1: Recherche basique dans une chaîne
    char str1[] = "Hello World";
    char *result1 = ft_memchr(str1, 'W', strlen(str1));
    char *expected1 = memchr(str1, 'W', strlen(str1));
    printf("Test 1:\n");
    printf("ft_memchr: %s\n", result1);
    printf("memchr: %s\n\n", expected1);

    // Test 2: Recherche d'un caractère qui n'existe pas
    char str2[] = "Hello World";
    char *result2 = ft_memchr(str2, 'Z', strlen(str2));
    char *expected2 = memchr(str2, 'Z', strlen(str2));
    printf("Test 2:\n");
    printf("ft_memchr: %s\n", result2 == NULL ? "NULL" : result2);
    printf("memchr: %s\n\n", expected2 == NULL ? "NULL" : expected2);

    // Test 3: Recherche avec n = 0
    char str3[] = "Hello World";
    char *result3 = ft_memchr(str3, 'H', 0);
    char *expected3 = memchr(str3, 'H', 0);
    printf("Test 3:\n");
    printf("ft_memchr: %s\n", result3 == NULL ? "NULL" : result3);
    printf("memchr: %s\n\n", expected3 == NULL ? "NULL" : expected3);

    // Test 4: Recherche dans un tableau d'entiers
    int tab[] = {1, 2, 3, 4, 5};
    int search = 3;
    int *result4 = ft_memchr(tab, search, sizeof(tab));
    int *expected4 = memchr(tab, search, sizeof(tab));
    printf("Test 4:\n");
    printf("ft_memchr: %s\n", result4 != NULL ? "Found" : "Not found");
    printf("memchr: %s\n", expected4 != NULL ? "Found" : "Not found");

    return (0);
}
*/
