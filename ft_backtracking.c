/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:54:25 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/08 13:35:01 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_backtracking(char **tetri, char *dest, int ssqrt)
{
	int		x;
	int		i;
	char	*c;
	int		len;

	x = 0;
	i = 0;
	len = 0;;
	c = ft_strnew(len);
	while (ft_nexttetri(tetri, dest, x) != -1)
	{
		//ft_putendl("Je suis dans Backtracking et dans la boucle, youpitralala");
		x = ft_nexttetri(tetri, dest, x);
		i = ft_checkplace(dest, tetri[x], ssqrt);
		if (i != -1)
		{
			//ft_putendl("Est-ce que tu vas dans le if ??");
			ft_display(tetri[x], dest, i, ssqrt);
			i = 0;
			len++;
			c = ft_savechar(tetri[x], len, c);
			x = 0;
		}
		else
		{
			x = ft_nexttetri(tetri, dest, x + 1);
			while (x == -1 && ft_destchar(dest) == 1)
			{
				ft_putendl("coucou !!!!!!!");
				len--;
				ft_dellasttetri(dest, c[len - 1]);
				/*ft_putendl("Valeur de c :");
				ft_putchar(c[len]);
				ft_putchar('\n');
				ft_putendl(c);
				ft_putnbr(len);
				ft_putchar('\n');*/
				x = ft_nexttetri(tetri, dest, ft_convertclen(tetri, c[len - 1]) + 1);
				c = ft_dellastchar(c, len);
				ft_putnbr(x);
				ft_putchar('\n');
			}
			ft_putendl(dest);
		}
	}
	ft_putendl("Je suis sorti");
	if (ft_checkupdest(dest, tetri) == 0)
	{
		ssqrt = ssqrt + 1;
		dest = ft_upsizedest(dest, ssqrt);
		return (ft_backtracking(tetri, dest, ssqrt));
	}
	return (dest);
}
