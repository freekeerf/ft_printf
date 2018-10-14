/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:45:35 by evlasov           #+#    #+#             */
/*   Updated: 2017/11/03 19:46:31 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rez;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		if (!(rez = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (0);
		while (s1[i])
		{
			rez[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			rez[i] = s2[j];
			i++;
			j++;
		}
		return (rez);
	}
	return (0);
}
