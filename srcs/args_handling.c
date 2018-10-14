/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:44:32 by evlasov           #+#    #+#             */
/*   Updated: 2018/09/28 20:44:33 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		width_precision(const char *format, int i, t_flags *flags)
{
	if (format[i] >= '0' && format[i] <= '9')
		flags->width = ft_atoi(format + i);
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	if (format[i] == '.')
	{
		i++;
		while (format[i] == '.')
		{
			flags->hash = 0;
			flags->zero = 0;
			i++;
		}
		flags->precision = ft_atoi(format + i);
		if (flags->precision == 0)
			flags->point = 1;
	}
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	if (format[i] == '+' || format[i] == ' ' || format[i] == '-'
		|| format[i] == '0' || format[i] == '#' || format[i] == '.')
		flags_handling(format, i++, flags);
	return (size_mod(format, i, flags));
}

int		flags_handling(const char *format, int i, t_flags *flags)
{
	while (format[i] == '+' || format[i] == ' ' || format[i] == '-'
		|| format[i] == '0' || format[i] == '#')
	{
		if (format[i] == '+')
			flags->plus = 1;
		else if (format[i] == '-')
			flags->minus = 1;
		else if (format[i] == '#')
			flags->hash = 1;
		else if (format[i] == ' ')
			flags->space = 1;
		else if (format[i] == '0')
			flags->zero = 1;
		i++;
	}
	return (width_precision(format, i, flags));
}

void	args_helper(t_flags *flags)
{
	if (flags->k > 3000)
	{
		ft_putstr(flags->result);
		ft_bzero(flags->result, flags->k);
		flags->rez += flags->k;
		flags->k = 0;
	}
	ft_init(flags);
}

int		per_helper(t_flags *flags, const char *format, int i)
{
	if (flags->width == 0)
		return (i - 1);
	if (flags->minus == 0)
		while (flags->width > 1)
		{
			if (flags->zero == 1)
				flags->result[flags->k++] = '0';
			else
				flags->result[flags->k++] = ' ';
			flags->width--;
		}
	flags->result[flags->k++] = format[i];
	if (flags->minus == 1)
		while (flags->width > 1)
		{
			flags->result[flags->k++] = ' ';
			flags->width--;
		}
	return (i);
}

void	args_handling(const char *format, va_list args, t_flags *flags)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			flags->result[flags->k++] = format[i];
		else if (format[i] == '%' && format[i + 1] == '%')
			flags->result[flags->k++] = format[i++];
		else if (format[i] == '%')
		{
			flags->count++;
			i = flags_handling(format, i + 1, flags);
			if (flags->conversion != 0 && flags->conversion != '%')
				apply_flags(flags->conversion, args, flags);
			else if (flags->conversion == '%')
				print_per(flags);
			else
				i = per_helper(flags, format, i);
			args_helper(flags);
		}
		i++;
	}
	if (flags->result)
		ft_putstr(flags->result);
}
