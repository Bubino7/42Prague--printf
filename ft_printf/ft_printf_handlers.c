/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbubak <jbubak@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:17:18 by jbubak            #+#    #+#             */
/*   Updated: 2025/07/21 21:15:14 by jbubak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_c(va_list args)
{
	char	c;
	int		res;

	c = (char)va_arg(args, int);
	res = ft_putchar_safe(c);
	if (res == -1)
		return (-1);
	return (1);
}

int	ft_handle_s(va_list args)
{
	char	*s;
	int		res;

	s = va_arg(args, char *);
	if (s == NULL)
	{
		res = ft_putstr_safe("(null)");
		return (res);
	}
	res = ft_putstr_safe(s);
	if (res == -1)
		return (-1);
	return (ft_strlen(s));
}

int	ft_handle_d(va_list args)
{
	int	d;
	int	res;

	d = va_arg(args, int);
	res = ft_putnbr_safe(d);
	if (res == -1)
		return (-1);
	return (ft_nbrlen(d));
}

int	ft_handle_unsigned(va_list args)
{
	unsigned int	u;
	int				res;

	u = va_arg(args, unsigned int);
	res = ft_putnbr_unsigned(u);
	if (res == -1)
		return (-1);
	return (ft_nbrlen_unsigned(u));
}
