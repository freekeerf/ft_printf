/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:40:33 by evlasov           #+#    #+#             */
/*   Updated: 2017/10/29 16:40:34 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int		a;

	a = 0;
	while ((unsigned char)s1[a] == (unsigned char)s2[a] && s2[a])
		a++;
	if (s1[a] == '\0' && s2[a] == '\0')
		return (0);
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
