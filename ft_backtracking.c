/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:54:25 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/18 16:36:09 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_backtracking(char **tetri, char *dest, int ssqrt)
{
	int		x;
	int		i;
	int		tmp;
	char	*c;
	int		len;

	x = 0;
	i = 0;
	tmp = 0;
	len = 0;;
	c = ft_strnew(len);
	while (ft_nexttetri(tetri, dest, x) != -1)
	{
		x = ft_nexttetri(tetri, dest, x);
		i = ft_checkplace(dest, tetri[x], ssqrt);
		if (i != -1)
		{
			ft_display(tetri[x], dest, i, ssqrt);
			tmp = x;
			x = 0;
			i = 0;
			len++;
			c = ft_savechar(tetri[x], len, c);
		}
		else
		{
			x++;
			if (tetri[x] == '\0' && ft_destchar(dest) == 1)
			{
				ft_dellasttetri(dest, c[len]);
				x = tmp + 1;
				len--;
				c = ft_dellastchar(c, len);
			}
		}
	}
	if (ft_checkupdest(dest, tetri) == 0)
	{
		ssqrt = ssqrt + 1;
		dest = ft_upsizedest(dest, ssqrt);
		return (ft_backtracking(tetri, dest, ssqrt));
	}
	return (dest);
}
