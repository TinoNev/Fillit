/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:10:46 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/15 14:47:05 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_tablen(char **tetri)
{
	int y;
	int x;
	char c;

	y = 0;
	x = 0;
	c = 0;
	while (tetri[x] != '\0')
	{
		x++;
	}
	y = ft_ispoint(tetri[x - 1], y);
	c = tetri[x - 1][y];
	return (c);
}

char	*ft_backtracking2(char **tetri, char *dest, int ssqrt)
{
	int x;
	int i;
	char *c;
	int len;

	x = 0;
	i = 0;
	len = 0;
	c = ft_strnew(len);
	while (ft_checkupdest(dest, tetri) == 0)
	{
		while (ft_nexttetri(tetri, dest, x) != -1)
		{
			x = ft_nexttetri(tetri, dest, x);
			i = ft_checkplace(dest, tetri[x], ssqrt);
			if (i != -1)
			{
				dest = ft_display(tetri[x], dest, i, ssqrt);
				i = 0;
				len++;
				c = ft_savechar(tetri[x], len, c);
				x = 0;
			}
			else
				x++;
		}
		if (ft_checkupdest(dest, tetri) == 0)
		{
			if (len == 1 && c[0] == ft_tablen(tetri))
			{
				ssqrt = ssqrt + 1;
				dest = ft_upsizedest(dest, ssqrt);
				return (ft_backtracking2(tetri, dest, ssqrt));
			}
			x = ft_convertclen(tetri, c[len - 1]) + 1;
			len--;
			ft_dellasttetri(dest, c[len]);
			c = ft_dellastchar(c, len);
			if (ft_nexttetri(tetri, dest, x) == -1 && len > 0)
			{
				if (len == 1 && c[0] == ft_tablen(tetri))
				{
					ssqrt = ssqrt + 1;
					dest = ft_upsizedest(dest, ssqrt);
					return (ft_backtracking2(tetri, dest, ssqrt));
				}
				x = ft_convertclen(tetri, c[len - 1]) + 1;
				len--;
				ft_dellasttetri(dest, c[len]);
				c = ft_dellastchar(c, len);
			}
		}
	}
	return (dest);
}
