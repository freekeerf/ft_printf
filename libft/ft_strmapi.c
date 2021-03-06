/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:25:35 by evlasov           #+#    #+#             */
/*   Updated: 2017/11/03 19:26:40 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			rez[i] = f(i, *s);
			s++;
			i++;
		}
		rez[i] = '\0';
		return (rez);
	}
	return (0);
}
