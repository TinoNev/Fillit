/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:55:24 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/05 17:55:33 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "include.h"

int			ft_countsize(char *file)
{
	int		fd;
	int		ret;
	int		size;
	char	*buf;

	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		size++;
	}
	close(fd);
	size = ((size - 1) * 5) + ((size / 4) - 1);
	return (size);
}

char		*ft_convert(char *file, int size)
{
	int		fd;
	int		ret;
	char	*buf;
	char	*dst;

	buf = ft_strnew(size);
	dst = ft_strnew(size);
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buf, size)))
	{
		buf[ret] = '\0';
		ft_strcpy(dst, buf);
	}
	close(fd);
	return (dst);
}
