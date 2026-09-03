/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouzekr <ibouzekr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:24:09 by ibouzekr          #+#    #+#             */
/*   Updated: 2025/10/31 19:14:46 by ibouzekr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*head;
	t_list	*ptrholder;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	head = *lst;
	while (head != NULL)
	{
		(*del)(head -> content);
		ptrholder = head;
		head = head -> next;
		free(ptrholder);
	}
	*lst = NULL;
}
