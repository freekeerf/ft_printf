/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:40:12 by evlasov           #+#    #+#             */
/*   Updated: 2017/10/29 16:40:13 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int		a;
	int		b;

	a = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[a])
	{
		b = 0;
		while (to_find[b] == str[a + b])
		{
			if (to_find[b + 1] == '\0')
				return ((char*)(str + a));
			b++;
		}
		a++;
	}
	return (0);
}
