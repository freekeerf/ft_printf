/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 20:03:05 by evlasov           #+#    #+#             */
/*   Updated: 2018/09/29 20:03:06 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	to_rez_s(t_flags *flags, int space, int zero, int i)
{
	if (flags->minus == 0)
		while (space > 0)
		{
			flags->result[flags->k++] = ' ';
			space--;
		}
	while (zero > 0)
	{
		flags->result[flags->k++] = '0';
		zero--;
	}
	while (flags->tmp != NULL && flags->tmp[i] && flags->point == 0)
		flags->result[flags->k++] = flags->tmp[i++];
	if (flags->minus == 1)
		while (space > 0)
		{
			flags->result[flags->k++] = ' ';
			space--;
		}
}

void	print_s(t_flags *flags)
{
	int		zero;
	int		space;
	int		len;

	len = 6;
	if (flags->tmp != NULL)
		len = ft_strlen(flags->tmp);
	else
		flags->tmp = "(null)";
	zero = 0;
	space = 0;
	if (flags->point == 1)
		len = 0;
	if (flags->minus == 1)
		flags->zero = 0;
	if (len >= flags->precision)
		flags->precision = 0;
	if (flags->width != 0)
		space = flags->width - len;
	if (flags->zero == 1 && flags->width != 0)
		zero = flags->width - len;
	if (space != 0)
		space = space - zero;
	to_rez_s(flags, space, zero, 0);
}

int		apply_sl(va_list args, t_flags *flags)
{
	wchar_t		*test;
	int			i;
	int			k;
	char		*tmp;
	int			a;

	i = 0;
	k = 0;
	tmp = ft_memalloc(100);
	test = va_arg(args, wchar_t*);
	if (!test)
		test = L"(null)";
	k = unicode(test[i++], tmp, k);
	a = k;
	while (test[i])
		k = unicode(test[i++], tmp, k);
	flags->tmp = tmp;
	ft_strdel(&tmp);
	if (flags->precision < (int)ft_strlen(flags->tmp))
	{
		i = flags->precision / a;
		flags->precision = i * a;
	}
	return (0);
}

int		apply_s(va_list args, t_flags *flags)
{
	char	*tmp;

	flags->plus = 0;
	flags->space = 0;
	if (flags->size == 'l' || flags->conversion == 'S')
		apply_sl(args, flags);
	else
		flags->tmp = va_arg(args, char*);
	if (flags->tmp && flags->precision != 0
		&& flags->precision < (int)ft_strlen(flags->tmp))
	{
		tmp = ft_memalloc(flags->precision + 4);
		ft_strncpy(tmp, flags->tmp, flags->precision);
		flags->tmp = tmp;
		flags->precision = 0;
	}
	return (0);
}
