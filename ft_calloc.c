/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouzekr <ibouzekr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:53:18 by ibouzekr          #+#    #+#             */
/*   Updated: 2025/11/03 12:01:03 by ibouzekr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	nmemb, size_t	size)
{
	size_t	bytes_needed;
	char	*ptr;

	bytes_needed = nmemb * size;
	if (nmemb != 0 && size != 0 && bytes_needed / size != nmemb)
		return (NULL);
	ptr = (char *)malloc(bytes_needed);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, bytes_needed);
	return (ptr);
}
