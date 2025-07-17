/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbubak <jbubak@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:59:48 by jbubak            #+#    #+#             */
/*   Updated: 2025/07/17 19:22:50 by jbubak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_handle_c(args));
	else if (specifier == 's')
		return (ft_handle_s(args));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_handle_d(args));
	else if (specifier == 'u')
		return (ft_handle_unsigned(args));
	else if (specifier == 'x')
		return (ft_handle_hex_lower(args));
	else if (specifier == 'X')
		return (ft_handle_hex_upper(args));
	else if (specifier == 'p')
		return (ft_handle_pointer(args));
	else if (specifier == '%')
		return (ft_handle_percent(args));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		str_len;
	int		i;

	i = 0;
	str_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			str_len += ft_handle_specifier(format[i], args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			str_len++;
		}
		i++;
	}
	va_end(args);
	return (str_len);
}
