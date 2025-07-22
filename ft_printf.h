/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbubak <jbubak@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:58:01 by jbubak            #+#    #+#             */
/*   Updated: 2025/07/21 21:10:14 by jbubak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_nbrlen(int n);
int	ft_putnbr_base(unsigned long n, char *base, int base_len);
int	ft_nbrlen_base(unsigned long n, int base_len);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_nbrlen_unsigned(unsigned int n);
int	ft_putchar_safe(char c);
int	ft_putstr_safe(char *s);
int	ft_putnbr_safe(int n);
int	ft_handle_c(va_list args);
int	ft_handle_s(va_list args);
int	ft_handle_d(va_list args);
int	ft_handle_unsigned(va_list args);
int	ft_handle_hex_lower(va_list args);
int	ft_handle_hex_upper(va_list args);
int	ft_handle_pointer(va_list args);
int	ft_handle_percent(va_list args);

#endif
