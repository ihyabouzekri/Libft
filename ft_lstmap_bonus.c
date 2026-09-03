/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouzekr <ibouzekr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:24:51 by ibouzekr          #+#    #+#             */
/*   Updated: 2025/11/01 16:04:19 by ibouzekr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_node_content(t_list *lst, t_list *nodeptr, void *(*f)(void *))
{
	nodeptr -> content = (*f)(lst -> content);
	nodeptr -> next = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*nodeptr;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	temp = NULL;
	head = NULL;
	while (lst)
	{
		nodeptr = malloc(sizeof(t_list));
		if (!nodeptr)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_node_content(lst, nodeptr, f);
		if (!head)
			head = nodeptr;
		if (temp)
			temp -> next = nodeptr;
		temp = nodeptr;
		lst = lst -> next;
	}
	return (head);
}
