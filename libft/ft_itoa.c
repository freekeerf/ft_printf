/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:25:39 by evlasov           #+#    #+#             */
/*   Updated: 2017/11/03 20:26:10 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int n)
{
	int		count;

	count = 1;
	if (n == -2147483648)
		return (11);
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

static int	ft_minint(char *buf)
{
	buf[0] = '-';
	buf[1] = '2';
	return (147483648);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*buf;
	int		len;

	if (!(buf = ft_memalloc(ft_nlen(n) + 1)))
		return (0);
	i = ft_nlen(n) - 1;
	len = 2;
	if (n == -2147483648)
		n = ft_minint(buf);
	else if (n < 0)
	{
		buf[0] = '-';
		n = -n;
		len = 1;
	}
	else
		len = 0;
	while (i >= len)
	{
		buf[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (buf);
}
