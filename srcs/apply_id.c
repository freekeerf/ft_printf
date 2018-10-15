/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 20:02:56 by evlasov           #+#    #+#             */
/*   Updated: 2018/09/29 20:02:58 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	to_rez_id(t_flags *flags, int space, int zero, int i)
{
	if (flags->minus == 0)
		while (space > 0)
		{
			flags->result[flags->k++] = ' ';
			space--;
		}
	if (flags->tmp[i] == '-')
		flags->result[flags->k++] = flags->tmp[i++];
	if (flags->plus == 1)
		flags->result[flags->k++] = '+';
	else if (flags->space == 1)
		flags->result[flags->k++] = ' ';
	while (zero > 0)
	{
		flags->result[flags->k++] = '0';
		zero--;
	}
	while (flags->tmp[i] && (flags->point == 0 || flags->tmp[0] != '0'))
		flags->result[flags->k++] = flags->tmp[i++];
	if (flags->minus == 1)
		while (space > 0)
		{
			flags->result[flags->k++] = ' ';
			space--;
		}
	ft_strdel(&flags->tmp);
}

void	chech_id(t_flags *flags, int len)
{
	if (flags->plus == 1)
		flags->space = 0;
	if (flags->minus == 1)
		flags->zero = 0;
	if (flags->hash == 1)
		flags->zero = 1;
	flags->hash = 0;
	if (len >= flags->width || flags->precision >= flags->width)
		flags->width = 0;
	if (flags->precision != 0)
		flags->zero = 0;
	if (flags->tmp[0] == '-')
	{
		flags->plus = 0;
		flags->space = 0;
	}
}

void	print_id(t_flags *flags, int len)
{
	int		zero;
	int		space;
	int		sp;

	sp = 0;
	space = 0;
	zero = 0;
	chech_id(flags, len);
	if (flags->tmp[0] == '-' || (flags->point == 1 && flags->tmp[0] == '0'))
		len--;
	if (flags->plus == 1 || flags->space == 1 || flags->tmp[0] == '-')
		sp = 1;
	if (flags->width != 0)
		space = flags->width - len - sp;
	if (flags->precision != 0)
		zero = flags->precision - len;
	else if (flags->zero == 1 && flags->width != 0)
		zero = flags->width - len - sp;
	if (zero < 0)
		zero = 0;
	if (space != 0)
		space = space - zero;
	to_rez_id(flags, space, zero, 0);
}

int		apply_id(va_list args, t_flags *flags)
{
	char	*tmp;

	if (flags->conversion == 'D')
		flags->size = 'l';
	if (flags->size == 'z')
		tmp = ft_itoa_ll(va_arg(args, ssize_t));
	else if (flags->size == 'j')
		tmp = ft_itoa_ll(va_arg(args, intmax_t));
	else if (flags->size == 'L')
		tmp = ft_itoa_ll(va_arg(args, long long));
	else if (flags->size == 'l')
		tmp = ft_itoa_ll(va_arg(args, long));
	else if (flags->size == 'h')
		tmp = ft_itoa_ll((short)va_arg(args, void*));
	else if (flags->size == 'H')
		tmp = ft_itoa_ll((signed char)va_arg(args, void*));
	else
		tmp = ft_itoa_ll(va_arg(args, int));
	flags->tmp = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (0);
}
