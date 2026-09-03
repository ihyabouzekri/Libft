/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouzekr <ibouzekr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:40:47 by ibouzekr          #+#    #+#             */
/*   Updated: 2025/10/31 17:47:56 by ibouzekr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_int_cutter(int n, char *tem_buf, int *index)
{
	if (n >= 10)
		ft_int_cutter(n / 10, tem_buf, index);
	tem_buf[*index] = '0' + (n % 10);
	(*index)++;
	return ;
}

char	*ft_itoa(int n)
{
	char	tem_buf[12];
	int		index;

	index = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		tem_buf[0] = '-';
		index++;
		n = -n;
	}
	ft_int_cutter (n, tem_buf, &index);
	tem_buf[index] = '\0';
	return (ft_strdup (tem_buf));
}
