/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_ll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 01:49:47 by evlasov           #+#    #+#             */
/*   Updated: 2018/10/12 01:49:48 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_unlen(uintmax_t n)
{
	int	count;

	count = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa_ll(uintmax_t n)
{
	int		i;
	char	*buf;

	i = ft_unlen(n) - 1;
	if (!(buf = ft_memalloc(i + 2)))
		return (0);
	if (n == 0)
	{
		buf = ft_strdup("0");
		return (buf);
	}
	while (n > 0)
	{
		buf[i--] = n % 10 + '0';
		n = n / 10;
		if (n == 0)
			break ;
	}
	return (buf);
}
