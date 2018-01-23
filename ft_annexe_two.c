/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexe_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:25:49 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/23 13:52:23 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_dellasttetri(char *dest, char *str)
{
	int i;
	int x;

	i = ft_ispoint(str, 0);
	x = 0;
	while (dest[x] != '\0')
	{
		if (dest[x] == str[i])
			dest[x] = '.';
		x++;
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
