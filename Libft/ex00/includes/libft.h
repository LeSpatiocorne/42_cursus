/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:19:26 by nidruon           #+#    #+#             */
/*   Updated: 2024/10/05 18:47:22 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int 	ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_str_is_alpha(char *str);
int		ft_str_is_numeric(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strdup(char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
