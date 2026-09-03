/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouzekr <ibouzekr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 00:32:42 by ibouzekr          #+#    #+#             */
/*   Updated: 2025/10/31 17:48:34 by ibouzekr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*bptr;
	size_t	i;

	bptr = (char *)s;
	i = 0;
	while (i < n)
	{
		if (bptr[i] == (char)c)
			return (&bptr[i]);
		i++;
	}
	return (NULL);
}
