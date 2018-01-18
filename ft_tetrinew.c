/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrisplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 10:25:17 by lchaillo          #+#    #+#             */
/*   Updated: 2018/01/18 15:00:50 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_sizetetri(char *str)
{
	int	i;
	int	n;
	int	size;

	size = 0;
	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	size = (i - n) / 16;
	return (size);
}

char			**ft_tetrisplit(char *str, int size)
{
	int		i;
	int		x;
	char	**tetri;

	x = 0;
	i = 19;
	if (!(tetri = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		tetri[x] = ft_strsub(str, i - 19, (i - (i - 19)));
		x++;
		if (str[i + 1] == '\n')
			i = i + 20;
		++i;
	}
	tetri[x] = NULL;
	return (tetri);
}

static char		**ft_tetricmp(char **s1, char **s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s2[j] && (ft_atoibin(s1[i]) % ft_atoibin(s2[j]) != 0))
			j++;
		if (s2[j] == '\0')
			return (NULL);
		else
			s1[i] = ft_strcpy(s1[i], s2[j]);
		j = 0;
		i++;
	}
	return (s1);
}

static char		**ft_alphatetri(char **tetri)
{
	int		x;
	int		y;
	char	a;

	x = 0;
	y = 0;
	a = 'A';
	while (tetri[x] != '\0')
	{
		while (tetri[x][y])
		{
			if (tetri[x][y] == '#')
				tetri[x][y] = a;
			y++;
		}
		a++;
		y = 0;
		x++;
	}
	return (tetri);
}

char			**ft_tetrinew(char *str)
{
	char	**tetri;
	char	**tab;
	int		x;

	x = 0;
	tab = ft_tabvalue();
	tetri = ft_tetrisplit(str, ft_sizetetri(str));
	tetri = ft_tetricmp(tetri, tab);
	if (tetri == NULL)
		return (NULL);
	tetri = ft_alphatetri(tetri);
	return (tetri);
}
