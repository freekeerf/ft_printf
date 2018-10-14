/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 13:48:22 by evlasov           #+#    #+#             */
/*   Updated: 2017/10/25 13:48:25 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(const void *str, int simb, size_t count)
{
	size_t			i;
	unsigned char	*st;

	st = (unsigned char*)str;
	i = 0;
	while (i < count)
	{
		st[i] = (unsigned char)simb;
		i++;
	}
	return (st);
}
