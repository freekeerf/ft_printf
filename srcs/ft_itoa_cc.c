/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_cc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 22:31:15 by evlasov           #+#    #+#             */
/*   Updated: 2018/10/01 22:31:16 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	ft_simb(int n)
{
	if (n < 10)
		return (n + '0');
	return (n + 87);
}

char	*helper(intmax_t n, int cc)
{
	int		i;
	int		minus;
	char	*tmp;

	i = 0;
	minus = 0;
	if (!(tmp = ft_memalloc(100)))
		return (NULL);
	if (n < 0)
	{
		minus = 1;
		n = -n;
	}
	while (n >= 0)
	{
		tmp[i++] = ft_simb((int)(n % cc));
		n = n / cc;
		if (n == 0)
			break ;
	}
	if (minus == 1)
		tmp[i] = '-';
	return (tmp);
}

int		ft_itoa_cc(intmax_t n, char **buf, int cc)
{
	int		i;
	int		k;
	char	*tmp;

	k = 0;
	if (cc < 2 || cc > 32)
		return (-1);
	tmp = helper(n, cc);
	i = ft_strlen(tmp) - 1;
	buf[0] = ft_memalloc(i + 2);
	while (i >= 0)
	{
		buf[0][k++] = tmp[i--];
	}
	free(tmp);
	return (0);
}
