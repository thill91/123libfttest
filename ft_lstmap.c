/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:35:09 by thill             #+#    #+#             */
/*   Updated: 2018/08/09 14:41:56 by thill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list *current;
	t_list *end;
	t_list *head;

	head = NULL;
	while (lst && f)
	{
		end = (t_list *)malloc(sizeof(t_list));
		if (end == NULL)
			return (NULL);
		end = f(lst);
		if (head == NULL)
		{
			head = end;
			current = end;
		}
		else
		{
			current->next = end;
			current = current->next;
		}
		lst = lst->next;
	}
	return (head);
}
