/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:54:25 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/18 11:40:37 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_backtracking(char **tetri, char *dest, int ssqrt)
{
	int		x;
	int		i;
	int		tmp;
	char	c;

	x = 0;
	i = 0;
	tmp = 0;
	c = 0;
	while (ft_nexttetri(tetri, dest, x) != -1)
	{
		x = ft_nexttetri(tetri, dest, x);
		i = ft_checkplace(dest, tetri[x], ssqrt);
		if (i != -1)
		{
			ft_display(tetri[x], dest, i, ssqrt);
			tmp = x;
			c = ft_savechar(tetri[x]);
			x = 0;
			i = 0;
		}
		else
		{
			x++;
			if (tetri[x] == '\0')
			{
				ft_dellasttetri(dest, c);
				x = tmp + 1;
			}
		}
	}
	if (ft_checkupdest(dest, ssqrt) == 0)
	{
		ssqrt = ssqrt + 1;
		ft_upsizedest(dest, ssqrt);
		return (ft_backtracking(tetri, dest, ssqrt));
	}
	return (dest);
}
