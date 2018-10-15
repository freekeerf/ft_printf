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
	int		len;

	len = uni_len(i);
	if (len == 1)
		tmp[k++] = i;
	else if (len == 2)
	{
		tmp[k++] = ((i >> 6) | 192);
		tmp[k++] = (((i << 26) >> 26) | 128);
	}
	else if (len == 3)
	{
		tmp[k++] = ((i >> 12) | 224);
		tmp[k++] = ((i << 20) >> 26 | 128);
		tmp[k++] = ((i << 26) >> 26 | 128);
	}
	else
	{
		tmp[k++] = ((i >> 4) | 240);
		tmp[k++] = ((i << 14) >> 26 | 128);
		tmp[k++] = ((i << 20) >> 26 | 128);
		tmp[k++] = ((i << 26) >> 26 | 128);
	}
	return (k);
}
