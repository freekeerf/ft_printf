/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:41:32 by evlasov           #+#    #+#             */
/*   Updated: 2017/10/25 18:41:33 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *to, void *from, int c, size_t size)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*f;

	t = (unsigned char *)to;
	f = (unsigned char *)from;
	i = 0;
	while (i < size)
	{
		t[i] = f[i];
		if (f[i] == (unsigned char)c)
			return (t + i + 1);
		i++;
	}
	return (0);
}
