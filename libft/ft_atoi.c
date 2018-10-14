/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:40:53 by evlasov           #+#    #+#             */
/*   Updated: 2017/10/29 16:40:54 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		b;
	int		min;
	int		ret;
	int		i;

	b = 0;
	ret = 0;
	min = 0;
	while ((str[b] >= 9 && str[b] <= 13) || str[b] == 32)
		b++;
	i = b;
	if (str[b] == '+' || str[b] == '-')
		if (str[b++] == '-')
			min = 1;
	while (str[b] >= '0' && str[b] <= '9')
		ret = ret * 10 + (str[b++] - '0');
	if (((b - i) > 18) && min == 0)
		return (-1);
	if (((b - i) > 18) && min == 1)
		return (0);
	if (min == 1)
		ret = -ret;
	return (ret);
}
