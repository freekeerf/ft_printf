/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:20:10 by evlasov           #+#    #+#             */
/*   Updated: 2017/11/03 20:21:23 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_endsimb(char const *s)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			n = i;
		i++;
	}
	return (n);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		ends;
	char	*rez;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	ends = ft_endsimb(s);
	if (ends == 0 || ends == i)
	{
		rez = (char*)malloc(1);
		rez[0] = '\0';
		return (rez);
	}
	if (!(rez = (char*)malloc(sizeof(char) * (ends - i + 2))))
		return (NULL);
	while (i <= ends)
		rez[j++] = s[i++];
	rez[j] = '\0';
	return (rez);
}
