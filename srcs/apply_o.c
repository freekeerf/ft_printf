/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 20:47:30 by evlasov           #+#    #+#             */
/*   Updated: 2018/10/01 20:47:31 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	to_rez_o(t_flags *flags, int space, int zero, int i)
{
	if (flags->minus == 0)
		while (space > 0)
		{
			flags->result[flags->k++] = ' ';
			space--;
		}
	if (flags->hash == 1)
		flags->result[flags->k++] = '0';
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
	ft_bzero(flags->tmp, ft_strlen(flags->tmp));
}

void	print_o(t_flags *flags, int len)
{
	int		zero;
	int		space;

	zero = 0;
	space = 0;
	if (flags->minus == 1)
		flags->zero = 0;
	if (len >= flags->precision)
		flags->precision = 0;
	if (flags->hash == 1)
		len += 1;
	if (flags->point == 1 && flags->tmp[0] == '0')
		len--;
	if (flags->width != 0)
		space = flags->width - len;
	if (flags->precision != 0)
		zero = flags->precision - len;
	else if (flags->zero == 1 && flags->width != 0)
		zero = flags->width - len;
	if (space != 0)
		space = space - zero;
	to_rez_o(flags, space, zero, 0);
}

int		apply_o(va_list args, t_flags *flags)
{
	intmax_t	i;
	char		*buf;

	if (flags->conversion == 'O')
		flags->size = 'l';
	if (flags->size == 'z')
		i = (va_arg(args, size_t));
	else if (flags->size == 'j')
		i = (va_arg(args, uintmax_t));
	else if (flags->size == 'L')
		i = (va_arg(args, unsigned long long));
	else if (flags->size == 'l')
		i = (va_arg(args, unsigned long));
	else if (flags->size == 'h')
		i = ((unsigned short)va_arg(args, void*));
	else if (flags->size == 'H')
		i = ((unsigned char)va_arg(args, void*));
	else
		i = (va_arg(args, unsigned int));
	if (i == 0 && flags->point == 0)
		flags->hash = 0;
	ft_uitoa_cc(i, &buf, 8, 0);
	flags->tmp = buf;
	ft_strdel(&buf);
	return (0);
}
