/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktwo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:56:35 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/16 14:16:10 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_dellasttetri(char *dest, char c)
{
	int i;

	i = 0;
	while (dest[i] != '\0')
	{
		if (dest[i] == c)
			dest[i] = '.';
		i++;
	}
	return (dest);
}

int		ft_checkupdest(char *dest, int ssqrt)
{
	int x;
	int p;

	p = 0;
	x = 0;
	while (x < ssqrt)
	{
		if (dest[x] == '.')
			p++;
		x++;
	}
	if (p != ssqrt)
		return (1);
	else
		return (0);
}

int		ft_nexttetri(char **tetri, char *dest, int x)
{
	int y;
	int i;

	y = 0;
	i = 0;
	while (tetri[x]!= '\0')
	{
		if (tetri[x][y] >= 'A' && tetri[x][y] <= 'Z')
		{
			while (dest[i] != tetri[x][y] && dest[i] != '\0')
					i++;
			if (dest[i] == '\0')
				return (x);
			else
			{
				y = 0;
				i = 0;
			}
		}
		x++;
		y++;
	}
	return (-1);
}