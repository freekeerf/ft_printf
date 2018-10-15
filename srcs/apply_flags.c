/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 18:39:58 by evlasov           #+#    #+#             */
/*   Updated: 2018/09/29 18:39:59 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_per(t_flags *flags)
{
	if (flags->minus == 0)
		while (flags->width > 1)
		{
			if (flags->zero == 1)
				flags->result[flags->k++] = '0';
			else
				flags->result[flags->k++] = ' ';
			flags->width--;
		}
	flags->result[flags->k++] = '%';
	if (flags->minus == 1)
		while (flags->width > 1)
		{
			flags->result[flags->k++] = ' ';
			flags->width--;
		}
}

int		apply_sign(t_flags *flags)
{
	if (ft_strchr("dDi", flags->conversion) != 0)
		print_id(flags, ft_strlen(flags->tmp));
	else if (flags->conversion == 'x' || flags->conversion == 'X')
		print_x(flags, ft_strlen(flags->tmp));
	else if (flags->conversion == 'o' || flags->conversion == 'O')
		print_o(flags, ft_strlen(flags->tmp));
	else if (flags->conversion == 'u' || flags->conversion == 'U')
		print_u(flags, ft_strlen(flags->tmp));
	else if (flags->conversion == 's' || flags->conversion == 'S')
	{
	//	if (flags->size != 'l' && flags->conversion != 'S')
			print_s(flags);
	}
	else if (flags->conversion == 'c' || flags->conversion == 'C')
	{
		if (flags->size != 'l' && flags->conversion != 'C')
			print_c(flags);
	}
	else if (flags->conversion == 'p')
		print_p(flags);
	else if (flags->conversion == '%')
		print_per(flags);
	return (0);
}

int		apply_flags(char c, va_list args, t_flags *flags)
{
	ft_printf("%s\n", flags->result);
	if (c == 'i' || c == 'd' || c == 'D')
		apply_id(args, flags);
	if (c == 's' || c == 'S')
		apply_s(args, flags);
	if (c == 'c' || c == 'C')
		apply_c(args, flags);
	if (c == 'o' || c == 'O')
		apply_o(args, flags);
	if (c == 'u' || c == 'U')
		apply_u(args, flags);
	if (c == 'x' || c == 'X')
		apply_x(args, flags);
	if (c == 'p')
		apply_p(args, flags);
	apply_sign(flags);
	return (0);
}
