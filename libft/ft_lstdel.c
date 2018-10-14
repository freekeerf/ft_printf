/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:17:12 by evlasov           #+#    #+#             */
/*   Updated: 2017/11/05 18:17:18 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;
	t_list		*list;

	if (*alst && alst && del)
	{
		list = *alst;
		while (list)
		{
			tmp = list;
			del((tmp->content), tmp->content_size);
			free(tmp);
			list = list->next;
		}
		*alst = NULL;
	}
}
