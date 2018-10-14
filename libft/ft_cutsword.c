/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutsword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:55:21 by evlasov           #+#    #+#             */
/*   Updated: 2017/11/26 19:55:22 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cutsword(const char *str, const char *s, int n)
{
	char	*buf;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (str && n >= 0)
	{
		i = ft_endsword(str, s, n);
		if (i < 0 || !(buf = (char*)malloc(sizeof(char) * (i - n + 2))))
			return (NULL);
		while (n <= i)
			buf[j++] = str[n++];
		buf[j] = '\0';
		return (buf);
	}
	return (NULL);
}
