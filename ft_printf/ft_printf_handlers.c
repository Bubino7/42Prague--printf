/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbubak <jbubak@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:17:18 by jbubak            #+#    #+#             */
/*   Updated: 2025/07/17 19:22:50 by jbubak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_c(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_handle_s(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_handle_d(va_list args)
{
	int	d;

	d = va_arg(args, int);
	ft_putnbr_fd(d, 1);
	return (ft_nbrlen(d));
}

int	ft_handle_unsigned(va_list args)
{
	unsigned int	u;

	u = va_arg(args, unsigned int);
	ft_putnbr_unsigned(u);
	return (ft_nbrlen_unsigned(u));
}
