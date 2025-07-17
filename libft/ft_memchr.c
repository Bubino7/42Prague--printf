/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbubak <jbubak@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:19:03 by jbubak            #+#    #+#             */
/*   Updated: 2025/05/30 19:19:03 by jbubak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	while (n)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		n--;
		ptr++;
	}
	return (NULL);
}
