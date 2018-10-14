/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:18:30 by evlasov           #+#    #+#             */
/*   Updated: 2017/11/05 18:18:31 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;
	t_list		*list_first;

	if (lst && f)
	{
		list = f(lst);
		list_first = list;
		while (lst->next)
		{
			lst = lst->next;
			list->next = f(lst);
			list = list->next;
		}
		return (list_first);
	}
	return (NULL);
}
