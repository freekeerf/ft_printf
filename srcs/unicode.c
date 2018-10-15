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

int		uni_len(unsigned int i)
{
	char	*size;
	int		len;

	ft_uitoa_cc(i, &size, 2, 0);
	len = ft_strlen(size);
	ft_strdel(&size);
	if (len <= 7)
		return (1);
	else if (len <= 11)
		return (2);
	else if (len <= 16)
		return (3);
	return (4);
}

int		unicode(unsigned int i, char *tmp, int k)
{
	char	*size;
	int		len;
	int		c;

	ft_uitoa_cc(i, &size, 2, 0);
	len = ft_strlen(size);
	ft_strdel(&size);
	if (len <= 7)
	{	
		tmp[k++] = i;
		return (k);
	}
	else if (len <= 11)
	{
		c = (i >> 6) | 192;
		tmp[k++] = c;
		c = ((i << 26) >> 26) | 128;
		tmp[k++] = c;
		return (k);
	}
	else if (len <= 16)
	{
		c = (i >> 12) | 224;
		tmp[k++] = c;
		c = (i << 20) >> 26 | 128;
		tmp[k++] = c;
		c = (i << 26) >> 26 | 128;
		tmp[k++] = c;
		return (k);
	}
	else
	{
		c = (i >> 18) | 240;
		tmp[k++] = c;
		c = (i << 14) >> 26 | 128;
		tmp[k++] = c;
		c = (i << 20) >> 26 | 128;
		tmp[k++] = c;
		c = (i << 26) >> 26 | 128;
		tmp[k++] = c;
		return (k);
	}
	return (0);
}
