/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:24:41 by evlasov           #+#    #+#             */
/*   Updated: 2017/11/03 19:25:16 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rez;
	int		size;
	int		i;

	i = 0;
	if (s && f)
	{
		size = ft_strlen(s);
		if (!(rez = ft_memalloc(size + 1)))
			return (0);
		while (*s)
		{
			rez[i] = f(*s);
			s++;
			i++;
		}
		rez[i] = '\0';
		return (rez);
	}
	return (0);
}
