/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:26:48 by evlasov           #+#    #+#             */
/*   Updated: 2018/09/26 20:26:49 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init(t_flags *flags)
{
	flags->count = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->size = 0;
	flags->conversion = 0;
	flags->point = 0;
}

int		ft_printf(char *format, ...)
{
	t_flags			*flags;
	va_list			args;
	int				i;

	printf("format = %s\n!", format);
//	while ()
//	printf("arg = %d\n!", va_arg(args, int));
	flags = ft_memalloc(sizeof(t_flags));
	ft_init(flags);
	flags->k = 0;
	flags->rez = 0;
	flags->result = ft_memalloc(4096);
	if (*format)
	{
		va_start(args, format);
		args_handling(format, args, flags);
		va_end(args);
	}
	i = flags->rez + flags->k;
	ft_strdel(&flags->result);
	free(flags);
	return (i);
}
