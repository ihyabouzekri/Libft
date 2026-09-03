/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouzekr <ibouzekr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:26:19 by ibouzekr          #+#    #+#             */
/*   Updated: 2025/11/02 17:27:19 by ibouzekr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_counter(const char *str, char c)
{
	int	counter;
	int	i;
	int	old_i;

	counter = 0;
	i = 0;
	while (str[i])
	{	
		while (str[i])
		{
			if (str[i] != c)
				break ;
			i++;
		}
		old_i = i;
		while (str[i])
		{
			if (str[i] == c)
				break ;
			i++;
		}
		if (i > old_i)
			counter++ ;
	}
	return (counter);
}

static void	ft_word_finder(const char *s, char sep, char **str_ptr, int *index)
{
	int	old_index;
	int	word_len;

	while (s[*index])
	{
		if (s[*index] != sep)
			break ;
		(*index)++ ;
	}
	old_index = *index;
	while (s[*index])
	{
		if (s[*index] == sep)
			break ;
		(*index)++ ;
	}
	if (*index > old_index)
	{
		word_len = (*index) - old_index;
		*str_ptr = malloc(word_len + 1);
		if (!*str_ptr)
			return ;
		ft_strlcpy(*str_ptr, &s[old_index], word_len + 1);
	}
}

static void	ft_free(char **ptr_arr)
{
	size_t	i;

	i = 0;
	while (ptr_arr[i] != NULL)
	{
		free(ptr_arr[i]);
		i++;
	}
	free (ptr_arr);
}

static char	**ft_alc_str(const char *s, char sep, int nb_words, char **ptr_arr)
{
	int		i;
	int		ptr_index;
	char	*str_ptr;

	i = 0;
	ptr_index = 0;
	while (s[i])
	{
		ft_word_finder(s, sep, &str_ptr, &i);
		if (ptr_index < nb_words)
		{
			ptr_arr[ptr_index] = str_ptr;
			if (ptr_arr[ptr_index] == NULL)
			{
				ft_free(ptr_arr);
				return (NULL);
			}
			ptr_index++;
		}
	}
	ptr_arr[ptr_index] = NULL;
	return (ptr_arr);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**ptr_to_arr;

	if (!s)
		return (NULL);
	words = ft_word_counter(s, c);
	ptr_to_arr = malloc(sizeof(char *) * (words + 1));
	if (ptr_to_arr == NULL)
		return (NULL);
	return (ft_alc_str(s, c, words, ptr_to_arr));
}
