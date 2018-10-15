/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 20:47:48 by evlasov           #+#    #+#             */
/*   Updated: 2018/10/01 20:47:49 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_p(t_flags *flags)
{
	int		i;

	i = 0;
	if (flags->tmp)
	{
		while (flags->tmp[i])
			flags->result[flags->k++] = flags->tmp[i++];
	}
	ft_strdel(&flags->tmp);
}

int		kostil_p2(t_flags *flags, int i)
{
	if (flags->precision == 0)
		return (2);
	if (flags->width > flags->precision)
	{
		while (flags->width > i + 2)
		{
			flags->result[flags->k++] = ' ';
			flags->width--;
		}
		flags->result[flags->k++] = '0';
		flags->result[flags->k++] = 'x';
	}
	else
	{
		flags->result[flags->k++] = '0';
		flags->result[flags->k++] = 'x';
		while (flags->precision > i)
		{
			flags->result[flags->k++] = '0';
			flags->precision--;
		}
	}
	return (0);
}

char	*ft_hex(unsigned long long p, t_flags *flags)
{
	char	*buf;
	char	*tmp;
	int		k;
	int		i;

	i = 0;
	if (!(tmp = ft_memalloc(100)))
		return (NULL);
	while (p > 0)
	{
		tmp[i++] = ft_simb((int)(p % 16));
		p = p / 16;
	}
	i = ft_strlen(tmp) - 1;
	buf = ft_memalloc(i + 4);
	k = kostil_p2(flags, i + 1);
	if (k == 2)
	{
		buf[0] = '0';
		buf[1] = 'x';
	}
	while (i >= 0)
		buf[k++] = tmp[i--];
	ft_strdel(&tmp);
	return (buf);
}

char	*kostil_p(int width, t_flags *flags, int point, int precision)
{
	int		i;
	char	*tmp;

	tmp = ft_memalloc(100);
	i = 0;
	if (flags->minus == 0 && flags->zero == 0)
		while (width-- > 3)
			tmp[i++] = ' ';
	tmp[i++] = '0';
	tmp[i++] = 'x';
	if (flags->zero == 1)
		while (width-- > 3)
			tmp[i++] = '0';
	if (point == 0)
	{
		tmp[i++] = '0';
		while (precision-- > 0)
			tmp[i++] = '0';
	}
	if (flags->minus == 1)
		while (width-- > 3)
			tmp[i++] = ' ';
	return (tmp);
}

int		apply_p(va_list args, t_flags *flags)
{
	unsigned long long	p;
	char				*tmp;

	flags->hash = 0;
	p = va_arg(args, unsigned long long);
	if (p == 0)
		tmp = kostil_p(flags->width, flags,
			flags->point, flags->precision - 1);
	else
		tmp = ft_hex(p, flags);
	flags->tmp = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (0);
}
