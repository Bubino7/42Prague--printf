/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbubak <jbubak@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:59:48 by jbubak            #+#    #+#             */
/*   Updated: 2025/07/22 09:32:29 by jbubak           ###   ########.fr       */
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

int	ft_printf_loop(const char *format, va_list args)
{
	int	str_len;
	int	i;
	int	res;

	i = 0;
	str_len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			res = ft_handle_specifier(format[i], args);
			if (res == -1)
				return (-1);
			str_len += res;
		}
		else
		{
			res = ft_putchar_safe(format[i]);
			if (res == -1)
				return (-1);
			str_len += res;
		}
		i++;
	}
	return (str_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = ft_printf_loop(format, args);
	va_end(args);
	return (res);
}
