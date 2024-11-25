/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:52:04 by nidruon           #+#    #+#             */
/*   Updated: 2024/11/25 13:28:03 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

int		ft_print_char(va_list args);
int		ft_print_hex(va_list args);
int		ft_print_int(va_list args);
int		ft_print_ptr(va_list args);
int		ft_print_str(va_list args);
int		ft_print_unsigned(va_list args);
int		ft_print_arg(char c, va_list args);
int		ft_printf(const char *format, ...);

int		ft_putnbr_base_fd(unsigned int nb, char *base, int fd);

#endif
