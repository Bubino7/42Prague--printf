/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbubak <jbubak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:57:49 by jbubak            #+#    #+#             */
/*   Updated: 2025/08/06 19:12:32 by jbubak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_hex_lower(va_list args)
{
	unsigned int	h;
	int				res;

	h = va_arg(args, unsigned int);
	res = ft_putnbr_base(h, "0123456789abcdef", 16);
	if (res == -1)
		return (-1);
	return (ft_nbrlen_base(h, 16));
}

int	ft_handle_hex_upper(va_list args)
{
	unsigned int	h;
	int				res;

	h = va_arg(args, unsigned int);
	res = ft_putnbr_base(h, "0123456789ABCDEF", 16);
	if (res == -1)
		return (-1);
	return (ft_nbrlen_base(h, 16));
}

int	ft_handle_pointer(va_list args)
{
	unsigned long	p;
	int				res;

	p = va_arg(args, unsigned long);
	if (p == 0)
	{
		res = ft_putstr_safe("(nil)");
		if (res == -1)
			return (-1);
		return (5);
	}
	res = ft_putstr_safe("0x");
	if (res == -1)
		return (-1);
	res = ft_putnbr_base(p, "0123456789abcdef", 16);
	if (res == -1)
		return (-1);
	return (2 + res);
}

int	ft_handle_percent(va_list args)
{
	int	res;

	(void)args;
	res = ft_putchar_safe('%');
	if (res == -1)
		return (-1);
	return (1);
}
