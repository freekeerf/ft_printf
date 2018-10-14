/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:22:27 by evlasov           #+#    #+#             */
/*   Updated: 2017/11/03 20:25:23 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wlen(char const *str, char c, int n)
{
	int		len;

	len = 0;
	while (str[n + len] != c && str[n + len])
		len++;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**rez;

	if (s && c)
	{
		i = 0;
		j = 0;
		if (!(rez = (char**)malloc(sizeof(char*) * (ft_strlen(s) + 1))))
			return (0);
		while (s[i])
		{
			if (s[i] == c)
				i++;
			else
			{
				rez[j++] = ft_strsub(s, i, ft_wlen(s, c, i));
				i = i + ft_wlen(s, c, i);
			}
		}
		rez[j] = 0;
		return (rez);
	}
	return (0);
}
