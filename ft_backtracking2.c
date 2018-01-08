/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:10:46 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/08 16:27:11 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
			ft_putendl("Je suis dans le if du checkup");
			ft_putendl(dest);
			x = ft_convertclen(tetri, c[len]);
			len--;
			ft_dellasttetri(dest, c[len]);
			c = ft_dellastchar(c, len);
			if (ft_nexttetri(tetri, dest, x + 1) == -1 && len > 0)
			{
				x = ft_convertclen(tetri, c[len - 1]) + 1;
				len--;
				ft_dellasttetri(dest, c[len]);
				c = ft_dellastchar(c, len);
				ft_putnbr(x);
				ft_putchar('\n');
				ft_putnbr(len);
				ft_putchar('\n');
			}
		}
	}
	return (dest);
}
