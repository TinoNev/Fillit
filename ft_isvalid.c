/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 10:50:47 by lchaillo          #+#    #+#             */
/*   Updated: 2018/01/23 15:07:39 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_usage(int argc)
{
	char	*usage;

	usage = "usage : fillit source_file";
	if (argc != 2)
	{
		ft_putendl(usage);
		return (0);
	}
	return (1);
}

static int	ft_strerror(char *str)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			str[i - 1] == '#' ? c++ : 0;
			str[i + 1] == '#' ? c++ : 0;
			str[i - 5] == '#' ? c++ : 0;
			str[i + 5] == '#' ? c++ : 0;
		}
		i++;
	}
	if (c == 6 || c == 8)
		return (1);
	else
		return (0);
}

static int	ft_error(char *str)
{
	char	**tetri;
	int		x;
	int		size;

	size = ft_sizetetri(str);
	tetri = ft_tetrisplit(str, size);
	x = 0;
	while (tetri[x] != '\0')
	{
		if (ft_strerror(tetri[x]) == 0)
			return (0);
		x++;
	}
	if (x > 26)
		return (0);
	return (1);
}

int			ft_is_valid(char *str)
{
	if (ft_valid_char(str) == 0 || ft_count_line(str) == 0
			|| ft_count_char(str) == 0)
	{
		ft_putendl(ERROR);
		return (0);
	}
	if (ft_are_four(str) == 0 || ft_error(str) == 0)
	{
		ft_putendl(ERROR);
		return (0);
	}
	return (1);
}
