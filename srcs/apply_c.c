/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 20:01:38 by evlasov           #+#    #+#             */
/*   Updated: 2018/10/01 20:01:39 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	force_print_c(t_flags *flags)
{
	ft_putstr(flags->result);
	flags->rez += flags->k + 1;
	ft_bzero(flags->result, flags->k);
	flags->k = 0;
	write(1, "\0", 1);
}

void	to_rez_c(t_flags *flags, int space, int zero, int i)
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
	if (flags->tmp != NULL && flags->tmp[i])
		flags->result[flags->k++] = flags->tmp[i++];
	else
		force_print_c(flags);
	if (flags->minus == 1)
		while (space > 0)
		{
			flags->result[flags->k++] = ' ';
			space--;
		}
}

void	print_c(t_flags *flags)
{
	int		zero;
	int		space;

	zero = 0;
	space = 0;
	if (flags->width != 0)
		space = flags->width - 1;
	if (flags->zero == 1 && flags->width != 0)
		zero = flags->width - 1;
	if (space != 0)
		space = space - zero;
	to_rez_c(flags, space, zero, 0);
}

int		apply_cl(va_list args, t_flags *flags)
{
	wchar_t		test;

	test = va_arg(args, wchar_t);
	ft_putstr(flags->result);
	flags->rez += flags->k + unicode(test);;
	ft_bzero(flags->result, flags->k);
	flags->k = 0;
	return (0);
}

int		apply_c(va_list args, t_flags *flags)
{
	char	*tmp;

	if (flags->size == 'l' || flags->conversion == 'C')
		return (apply_cl(args, flags));
	flags->precision = 0;
	tmp = ft_memalloc(2);
	tmp[0] = (char)(unsigned char)va_arg(args, void*);
	flags->tmp = tmp;
	ft_strdel(&tmp);
	return (0);
}
