/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:55:24 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/23 15:48:20 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_convert(char *file)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*dest;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	dest = ft_strdup(buf);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		dest = ft_strjoin(dest, buf);
	}
	close(fd);
	return (dest);
}
