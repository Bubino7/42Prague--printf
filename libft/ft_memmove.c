/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbubak <jbubak@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:37:44 by jbubak            #+#    #+#             */
/*   Updated: 2025/06/10 19:20:53 by jbubak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*newdest;
	const unsigned char	*tempsrc;

	if (!dest && !src)
		return (dest);
	newdest = dest;
	tempsrc = src;
	if ((newdest > tempsrc))
	{
		while (n)
		{
			newdest[n - 1] = tempsrc[n - 1];
			n--;
		}
	}
	else
	{
		while (n)
		{
			*newdest++ = *tempsrc++;
			n--;
		}
	}
	return (dest);
}
