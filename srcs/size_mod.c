/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 23:24:25 by evlasov           #+#    #+#             */
/*   Updated: 2018/10/12 23:24:26 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		helper2(t_flags *flags, const char *format, int i)
{
	if (format[i] == 'l' && flags->size != 'L'
		&& flags->size != 'z' && flags->size != 'j')
		flags->size = 'l';
	else if (format[i] == 'h' && format[i + 1] == 'h' && flags->size == 0)
	{
		flags->size = 'H';
		i++;
	}
	else if (format[i] == 'h' && (flags->size == 0 || flags->size == 'H'))
		flags->size = 'h';
	return (i);
}

int		size_mod_helper(const char *format, t_flags *flags, int i)
{
	if (format[i] == '+' || format[i] == ' ' || format[i] == '-'
		|| format[i] == '0' || format[i] == '#' || format[i] == '.')
		flags_handling(format, i++, flags);
	conversion_handling(format, i, flags);
	return (i);
}

int		conversion_handling(const char *format, int i, t_flags *flags)
{
	char	*str;

	str = "sSpdDioOuUxXcC";
	if (ft_strchr(str, format[i]) != 0)
		flags->conversion = ft_strchr(str, format[i])[0];
	else if (format[i] == '%')
		flags->conversion = '%';
	return (0);
}

int		size_mod(const char *format, int i, t_flags *flags)
{
	while (format[i] == 'z' || format[i] == 'j'
		|| format[i] == 'l' || format[i] == 'h')
	{
		if (format[i] == 'z')
			flags->size = 'z';
		else if (format[i] == 'j' && flags->size != 'z')
			flags->size = 'j';
		else if (format[i] == 'l' && format[i + 1] == 'l'
			&& flags->size != 'z' && flags->size != 'j')
		{
			flags->size = 'L';
			i++;
		}
		else if (format[i] != 'z' && format[i] != 'j' && format[i] != 'L')
			i = helper2(flags, format, i);
		i++;
	}
	return (size_mod_helper(format, flags, i));
}
