/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 22:17:15 by evlasov           #+#    #+#             */
/*   Updated: 2018/10/14 22:17:19 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		unicode(unsigned int i)
{
	char	*size;
	int		len;
	int		c;

	ft_uitoa_cc(i, &size, 2, 0);
	len = ft_strlen(size);
	ft_strdel(&size);
	if (len <= 7)
	{
		write(1, &i, 1);
		return (1);
	}
	else if (len <= 11)
	{
		c = (i >> 6) | 192;
		write(1, &c, 1);
		c = ((i << 26) >> 26) | 128;
		write(1, &c, 1);
		return (2);
	}
	else if (len <= 16)
	{
		c = (i >> 12) | 224;
		write(1, &c, 1);
		c = (i << 20) >> 26 | 128;
		write(1, &c, 1);
		c = (i << 26) >> 26 | 128;
		write(1, &c, 1);
		return (3);
	}
	else
	{
		c = (i >> 18) | 240;
		write(1, &c, 1);
		c = (i << 14) >> 26 | 128;
		write(1, &c, 1);
		c = (i << 20) >> 26 | 128;
		write(1, &c, 1);
		c = (i << 26) >> 26 | 128;
		write(1, &c, 1);
		return (4);
	}
	return (0);
}
