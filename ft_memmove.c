/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouzekr <ibouzekr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:16:17 by ibouzekr          #+#    #+#             */
/*   Updated: 2025/11/02 14:53:46 by ibouzekr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destptr;
	const char	*srcptr;

	destptr = (char *)dest;
	srcptr = (const char *) src;
	if (n == 0 || (dest == src))
		return (dest);
	if (destptr > srcptr)
	{
		while (n > 0)
		{
			n--;
			destptr[n] = srcptr[n];
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
