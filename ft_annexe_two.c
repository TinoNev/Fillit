/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexe_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:25:49 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/15 17:00:49 by tlaberro         ###   ########.fr       */
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

int		ft_checkupdest(char *dest, char **tetri)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (tetri[x] != '\0')
	{
		y = ft_ispoint(tetri[x], y);
		if (tetri[x][y] >= 'A' && tetri[x][y] <= 'Z')
		{
			while (dest[i] != tetri[x][y] && dest[i] != '\0')
				i++;
			if (dest[i] == '\0')
				return (0);
			else
			{
				y = 0;
				i = 0;
			}
		}
		x++;
	}
	return (1);
}

int		ft_nexttetri(char **tetri, char *dest, int x)
{
	int y;
	int i;

	y = 0;
	i = 0;
	while (tetri[x] != '\0')
	{
		y = ft_ispoint(tetri[x], y);
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
	}
	return (-1);
}

int		ft_convertclen(char **tetri, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tetri[x] != '\0')
	{
		y = ft_ispoint(tetri[x], y);
		if (tetri[x][y] != c)
			y = 0;
		else
			return (x);
		x++;
	}
	return (-2);
}
