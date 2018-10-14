/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:55:14 by evlasov           #+#    #+#             */
/*   Updated: 2017/10/25 18:55:16 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*des;
	const char	*sr;

	des = dst;
	sr = src;
	if (sr < des)
	{
		sr = src + n - 1;
		des = dst + n - 1;
		while (n--)
			*des-- = *sr--;
	}
	else if (sr > des)
	{
		while (n--)
			*des++ = *sr++;
	}
	return (dst);
}
