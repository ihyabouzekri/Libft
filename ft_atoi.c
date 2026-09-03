/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouzekr <ibouzekr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 00:33:10 by ibouzekr          #+#    #+#             */
/*   Updated: 2025/10/31 20:44:48 by ibouzekr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_intsetter(int sign, long long *result, const char *nptr)
{
	int	i;

	i = 0;
	while (48 <= nptr[i] && nptr[i] <= 57)
	{
		if (sign == 1 && *result > (LLONG_MAX - (nptr[i] - '0')) / 10)
		{
			*result = -1;
			return ;
		}
		if (sign == -1 && -(*result) < (LLONG_MIN + (nptr[i] - '0')) / 10)
		{
			*result = 0;
			return ;
		}
		*result = *result * 10 + (nptr[i] - '0');
		i++;
	}
}

int	ft_atoi(const char	*nptr)
{
	int			sign;
	int			i;
	long long	result;

	sign = 1;
	i = 0;
	result = 0;
	while (nptr[i] == 32 || (9 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sign *= -1;
		i++;
	}
	ft_intsetter(sign, &result, &nptr[i]);
	return (sign * result);
}
