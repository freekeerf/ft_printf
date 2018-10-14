/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:56:42 by evlasov           #+#    #+#             */
/*   Updated: 2017/11/26 19:56:44 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_filetostr(char *filename)
{
	char	*buf;
	int		fd;
	int		ret;
	int		size;

	ret = 0;
	while (ret == 0 || size <= ret)
	{
		if (!(fd = open(filename, O_RDONLY)))
			return (NULL);
		size = ret + 10000;
		if (!(buf = ft_memalloc(size + 1)))
			return (NULL);
		ret = read(fd, buf, size);
		close(fd);
		free(buf);
	}
	if (!(fd = open(filename, O_RDONLY)))
		return (NULL);
	if (!(buf = ft_memalloc(ret + 1)))
		return (NULL);
	read(fd, buf, ret);
	buf[ret + 1] = '\0';
	close(fd);
	return (buf);
}
