/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:13:26 by evlasov           #+#    #+#             */
/*   Updated: 2017/10/25 19:13:27 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int simb, size_t n)
{
	unsigned char	*st;
	size_t			i;

	st = (unsigned char*)str;
	i = 0;
	while (i < n)
	{
		if (st[i] == (unsigned char)simb)
			return (st + i);
		i++;
	}
	return (0);
}
