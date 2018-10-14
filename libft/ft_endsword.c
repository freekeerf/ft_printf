/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endsword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:55:13 by evlasov           #+#    #+#             */
/*   Updated: 2017/11/26 19:55:14 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_endsword(const char *str, const char *s, size_t n)
{
	int		i;
	int		j;

	j = 0;
	if (str && s)
	{
		while (j == 0 && str[n])
		{
			i = 0;
			while (s[i])
				if (str[n] == s[i++])
					j = 1;
			n++;
		}
		return (n - 1 - j);
	}
	return (-1);
}
