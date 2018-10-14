/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:07:28 by evlasov           #+#    #+#             */
/*   Updated: 2017/10/25 17:07:29 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*des;
	const char	*sr;

	i = 0;
	des = dst;
	sr = src;
	while (i < n)
	{
		des[i] = sr[i];
		i++;
	}
	return (des);
}
