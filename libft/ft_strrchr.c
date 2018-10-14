/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:40:00 by evlasov           #+#    #+#             */
/*   Updated: 2017/10/29 16:40:01 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	if (ft_strchr(src, c) == 0)
		return (0);
	while (*src)
		src++;
	while (*src != c)
		src--;
	return ((char*)src);
}
