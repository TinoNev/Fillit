/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:55:24 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/18 17:16:02 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_size(char *file)
{
	int		fd;
	int		ret;
	int		size;
	char	buf[BUF_SIZE + 1];

	size = BUF_SIZE;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		size++;
	}
	close(fd);
	size = ((size - 1) * 5) + ((size / 4) - 1);
	return (size);
}

char	*ft_convert(char *file, int size)
{
	int		fd;
	int		ret;
	char	*buf;
	char	*dest;

	buf = ft_strnew(size);
	dest = ft_strnew(size);
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buf, size)))
	{
		buf[ret] = '\0';
		ft_strcpy(dest, buf);
	}
	close(fd);
	return (dest);
}
