/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:01:52 by evlasov           #+#    #+#             */
/*   Updated: 2018/09/30 17:01:53 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_nlen(intmax_t n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa_ll(intmax_t n)
{
	int		i;
	char	*buf;

	if (n < -9223372036854775807)
	{
		buf = ft_strdup("-9223372036854775808");
		return (buf);
	}
	i = ft_nlen(n) - 1;
	if (!(buf = ft_memalloc(i + 2)))
		return (0);
	if (n < 0)
	{
		buf[0] = '-';
		n = -n;
	}
	while (n >= 0)
	{
		buf[i--] = n % 10 + '0';
		n = n / 10;
		if (n == 0)
			break ;
	}
	return (buf);
}
