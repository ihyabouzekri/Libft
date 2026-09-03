/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouzekr <ibouzekr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:57:29 by ibouzekr          #+#    #+#             */
/*   Updated: 2025/10/31 17:41:15 by ibouzekr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	i;
	size_t	j;

	if (!dst && size == 0)
		return (ft_strlen (src));
	dest_len = ft_strlen (dst);
	i = dest_len;
	j = 0;
	if (size <= dest_len)
		return (ft_strlen (src) + size);
	while (j < (size - dest_len - 1) && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen (src) + dest_len);
}
