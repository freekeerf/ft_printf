/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:40:19 by evlasov           #+#    #+#             */
/*   Updated: 2017/10/29 16:40:20 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	char	*tmp;

	tmp = ft_strstr(str, to_find);
	if ((tmp - str) + ft_strlen(to_find) > n)
		return (0);
	return (tmp);
}
