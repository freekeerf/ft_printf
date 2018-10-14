/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:44:07 by evlasov           #+#    #+#             */
/*   Updated: 2017/11/03 19:45:22 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*rez;

	if (s)
	{
		if (!(rez = ft_memalloc(len + 1)))
			return (0);
		rez = ft_strncpy(rez, (s + start), len);
		return (rez);
	}
	return (0);
}
