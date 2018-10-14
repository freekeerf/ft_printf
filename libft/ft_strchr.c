/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:39:51 by evlasov           #+#    #+#             */
/*   Updated: 2017/10/29 16:39:52 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *src, int c)
{
	while (*src)
	{
		if (*src == c)
			return ((char*)src);
		src++;
	}
	if (*src == (unsigned char)c)
		return ((char*)src);
	return (0);
}
