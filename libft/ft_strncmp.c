/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:40:40 by evlasov           #+#    #+#             */
/*   Updated: 2017/10/29 16:40:42 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	while (s1[a] && s2[a] && (unsigned char)s1[a] == (unsigned char)s2[a]
		&& a < n - 1)
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
