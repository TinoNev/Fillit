/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:24:12 by lchaillo          #+#    #+#             */
/*   Updated: 2017/12/18 16:12:35 by lchaillo         ###   ########.fr       */
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
	int n;

	i = 0;
	start = 0;
	tmp = x;
	n = x;
	while (src[i] != '\0')
	{
		start = ft_startvalue(src, i, start);
		i = ft_ispoint(src, i);
		if (x < ssqrt + n - 1 || (start == -1 && src[i - 1] == '.'))
			dest = ft_destcpy(src, dest, x, i);
		else
			dest = ft_destcpy(src, dest, x + start, i);
		src[i] == '\n' ? x = tmp + ssqrt : 0;
		src[i] == '\n' ? tmp = tmp + ssqrt + 1 : 0;
		x++;
		i++;
	}
	return (dest);
}
