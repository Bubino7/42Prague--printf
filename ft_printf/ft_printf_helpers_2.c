/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbubak <jbubak@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:02:24 by jbubak            #+#    #+#             */
/*   Updated: 2025/07/22 09:31:16 by jbubak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_safe(char c)
{
	int	res;

	res = write(1, &c, 1);
	if (res == -1)
		return (-1);
	return (1);
}

int	ft_putstr_safe(char *s)
{
	int	len;
	int	res;

	if (!s)
		return (-1);
	len = ft_strlen(s);
	res = write(1, s, len);
	if (res == -1)
		return (-1);
	return (res);
}

int	ft_putnbr_safe(int n)
{
	int		count;
	int		res;
	long	num;

	count = 0;
	num = n;
	if (num < 0)
	{
		res = ft_putchar_safe('-');
		if (res == -1)
			return (-1);
		count++;
		num = -num;
	}
	if (num >= 10)
	{
		res = ft_putnbr_safe(num / 10);
		if (res == -1)
			return (-1);
		count += res;
	}
	res = ft_putchar_safe("0123456789"[num % 10]);
	if (res == -1)
		return (-1);
	return (count + 1);
}
