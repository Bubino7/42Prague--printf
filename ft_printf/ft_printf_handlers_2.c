/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbubak <jbubak@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:57:49 by jbubak            #+#    #+#             */
/*   Updated: 2025/07/17 19:22:50 by jbubak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_hex_lower(va_list args)
{
	unsigned int	h;

	h = va_arg(args, unsigned int);
	ft_putnbr_base(h, "0123456789abcdef", 16);
	return (ft_nbrlen_base(h, 16));
}

int	ft_handle_hex_upper(va_list args)
{
	unsigned int	h;

	h = va_arg(args, unsigned int);
	ft_putnbr_base(h, "0123456789ABCDEF", 16);
	return (ft_nbrlen_base(h, 16));
}

int	ft_handle_pointer(va_list args)
{
	unsigned long	p;

	p = va_arg(args, unsigned long);
	ft_putstr_fd("0x", 1);
	if (p == 0)
	{
		ft_putchar_fd('0', 1);
		return (3);
	}
	ft_putnbr_base(p, "0123456789abcdef", 16);
	return (2 + ft_nbrlen_base(p, 16));
}

int	ft_handle_percent(va_list args)
{
	(void)args;
	ft_putchar_fd('%', 1);
	return (1);
}
