/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbubak <jbubak@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:51:16 by jbubak            #+#    #+#             */
/*   Updated: 2025/06/29 11:45:20 by jbubak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int len1, len2;

	// Test basic format specifiers
	len1 = ft_printf("%c\n", 'a');
	len2 = printf("%c\n", 'a');
	printf("ft_printf: %d, printf: %d\n\n", len1, len2);

	// Test string
	len1 = ft_printf("String: %s\n", "Hello 42!");
	len2 = printf("String: %s\n", "Hello 42!");
	printf("ft_printf: %d, printf: %d\n\n", len1, len2);

	// Test decimal
	len1 = ft_printf("%d\n", 42);
	len2 = printf("%d\n", 42);
	printf("ft_printf: %d, printf: %d\n\n", len1, len2);

	// Test integer
	len1 = ft_printf("Integer: %i\n", -123);
	len2 = printf("Integer: %i\n", -123);
	printf("ft_printf: %d, printf: %d\n\n", len1, len2);

	// Test unsigned
	len1 = ft_printf("Unsigned: %u\n", 429496);
	len2 = printf("Unsigned: %u\n", 429496);
	printf("ft_printf: %d, printf: %d\n\n", len1, len2);

	// Test hex lowercase
	len1 = ft_printf("Hex (lower): %x\n", 255);
	len2 = printf("Hex (lower): %x\n", 255);
	printf("ft_printf: %d, printf: %d\n\n", len1, len2);

	// Test hex uppercase
	len1 = ft_printf("Hex (upper): %X\n", 255);
	len2 = printf("Hex (upper): %X\n", 255);
	printf("ft_printf: %d, printf: %d\n\n", len1, len2);

	// Test pointer
	int test_var = 42;
	len1 = ft_printf("Pointer: %p\n", &test_var);
	len2 = printf("Pointer: %p\n", &test_var);
	printf("ft_printf: %d, printf: %d\n\n", len1, len2);

	// Test percent
	len1 = ft_printf("Percent: %%\n");
	len2 = printf("Percent: %%\n");
	printf("ft_printf: %d, printf: %d\n\n", len1, len2);

	return (0);
}
