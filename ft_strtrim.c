/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouzekr <ibouzekr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:44:18 by ibouzekr          #+#    #+#             */
/*   Updated: 2025/11/01 13:48:48 by ibouzekr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start_index(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr (set, s1[i]))
		i++;
	return (i);
}

static size_t	ft_end_index(char const *s1, char const *set, size_t start)
{
	size_t		s1_len;
	size_t		i;

	s1_len = ft_strlen(s1);
	if (s1_len == 0)
		return (0);
	i = s1_len - 1;
	while (i > start && ft_strchr (set, s1[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_index;
	size_t	end_index;
	size_t	trimmed_str_len;
	char	*str_ptr;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	start_index = ft_start_index (s1, set);
	end_index = ft_end_index (s1, set, start_index);
	if (start_index >= end_index)
		return (ft_strdup(""));
	trimmed_str_len = (end_index + 1) - start_index;
	str_ptr = (char *)malloc(trimmed_str_len + 1);
	if (str_ptr == NULL)
		return (NULL);
	ft_strlcpy(str_ptr, &s1[start_index], trimmed_str_len + 1);
	return (str_ptr);
}
