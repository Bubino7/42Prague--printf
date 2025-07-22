/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbubak <jbubak@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:14:49 by jbubak            #+#    #+#             */
/*   Updated: 2025/07/21 21:21:13 by jbubak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_base(unsigned long n, char *base, int base_len)
{
	int	count;
	int	res;

	count = 0;
	if (n >= (unsigned long)base_len)
	{
		res = ft_putnbr_base(n / base_len, base, base_len);
		if (res == -1)
			return (-1);
		count += res;
	}
	res = write(1, &base[n % base_len], 1);
	if (res == -1)
		return (-1);
	return (count + 1);
}

int	ft_nbrlen_base(unsigned long n, int base_len)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base_len;
		count++;
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;
	int	res;

	count = 0;
	if (n >= 10)
	{
		res = ft_putnbr_unsigned(n / 10);
		if (res == -1)
			return (-1);
		count += res;
	}
	res = write(1, &"0123456789"[n % 10], 1);
	if (res == -1)
		return (-1);
	return (count + 1);
}

int	ft_nbrlen_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
