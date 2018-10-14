/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 20:47:37 by evlasov           #+#    #+#             */
/*   Updated: 2018/10/01 20:47:38 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	to_rez_u(t_flags *flags, int space, int zero, int i)
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
	while (flags->tmp[i] && (flags->point == 0 || flags->tmp[0] != '0'))
		flags->result[flags->k++] = flags->tmp[i++];
	if (flags->minus == 1)
		while (space > 0)
		{
			flags->result[flags->k++] = ' ';
			space--;
		}
}

void	print_u(t_flags *flags, int len)
{
	int		zero;
	int		space;

	zero = 0;
	space = 0;
	if (len >= flags->precision)
		flags->precision = 0;
	if (flags->point == 1 && flags->tmp[0] == '0')
		len--;
	if (flags->width != 0)
		space = flags->width - len;
	if (flags->precision != 0)
		zero = flags->precision - len;
	else if (flags->zero == 1 && flags->width != 0 && flags->point == 0)
		zero = flags->width - len;
	if (space != 0)
		space = space - zero;
	to_rez_u(flags, space, zero, 0);
}

int		apply_u(va_list args, t_flags *flags)
{
	char		*tmp;

	if (flags->conversion == 'U')
		flags->size = 'l';
	if (flags->size == 'z')
		tmp = ft_uitoa_ll(va_arg(args, size_t));
	else if (flags->size == 'j')
		tmp = ft_uitoa_ll(va_arg(args, uintmax_t));
	else if (flags->size == 'L')
		tmp = ft_uitoa_ll(va_arg(args, unsigned long long));
	else if (flags->size == 'l')
		tmp = ft_uitoa_ll(va_arg(args, unsigned long));
	else if (flags->size == 'h')
		tmp = ft_uitoa_ll((unsigned short)va_arg(args, void*));
	else if (flags->size == 'H')
		tmp = ft_uitoa_ll((unsigned char)va_arg(args, void*));
	else
		tmp = ft_uitoa_ll(va_arg(args, unsigned int));
	flags->tmp = tmp;
	free(tmp);
	return (0);
}
