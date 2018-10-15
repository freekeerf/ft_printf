/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_cc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:42:09 by evlasov           #+#    #+#             */
/*   Updated: 2018/10/09 14:42:10 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	ft_simb_x(int n, int a)
{
	if (n < 10)
		return (n + '0');
	return (n + a);
}

char	*uhelper(uintmax_t n, int cc, int x)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = ft_memalloc(100)))
		return (NULL);
	if (n == 0)
		tmp[i++] = ft_simb_x((int)(n % cc), x);
	while (n > 0)
	{
		tmp[i++] = ft_simb_x((int)(n % cc), x);
		n = n / cc;
		if (n == 0)
			break ;
	}
	return (tmp);
}

int		ft_uitoa_cc(uintmax_t n, char **buf, int cc, int x)
{
	int		i;
	int		k;
	char	*tmp;

	k = 0;
	if (cc < 2 || cc > 32)
		return (-1);
	tmp = uhelper(n, cc, x);
	i = ft_strlen(tmp) - 1;
	buf[0] = ft_memalloc(i + 2);
	while (i >= 0)
	{
		buf[0][k++] = tmp[i--];
	}
//	ft_strdel(&tmp);
	return (0);
}
