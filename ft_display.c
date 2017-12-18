/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:24:12 by lchaillo          #+#    #+#             */
/*   Updated: 2017/12/18 09:39:51 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*ft_destcpy(char *src, char *dest, int x, int i)
{
	if (src[i] >= 'A' && src[i] <= 'Z')
	{
		dest[x] = src[i];
	}
	return (dest);
}

char			*ft_display(char *src, char *dest, int x, int ssqrt)
{
	int i;
	int tmp;
	int start;

	i = 0;
	start = 0;
	tmp = x;
	while (src[i] != '\0')
	{
		start = ft_startvalue(src, i, start);
		i = ft_ispoint(src, i);
		if (x < ssqrt || (start == -1 && src[i - 1] == '.'))
			dest = ft_destcpy(src, dest, x, i);
		else
			dest = ft_destcpy(src, dest, x + start, i);
		if (src[i] == '\n')
		{
			x = tmp + ssqrt;
			tmp = tmp + ssqrt + 1;
		}
		x++;
		i++;
	}
	return (dest);
}
