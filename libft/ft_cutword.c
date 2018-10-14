/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:53:35 by evlasov           #+#    #+#             */
/*   Updated: 2017/11/26 19:53:37 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cutword(const char *str, int n)
{
	char	*buf;
	int		i;
	int		j;

	j = 0;
	if (str && n >= 0)
	{
		while ((str[n] >= 9 && str[n] <= 13) || str[n] == 32)
			n++;
		i = ft_endword(str, n);
		if (i < 0)
			return (NULL);
		if (!(buf = (char*)malloc(sizeof(char) * (i - n + 2))))
			return (NULL);
		while (n <= i)
			buf[j++] = str[n++];
		buf[j] = '\0';
		return (buf);
	}
	return (NULL);
}
