/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:12:18 by lchaillo          #+#    #+#             */
/*   Updated: 2018/01/23 15:07:56 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_newdest(char *str)
{
	int		ssqrt;
	char	*dest;
	int		nb;
	char	**tetri;

	tetri = ft_tetrinew(str);
	if (tetri == NULL)
	{
		return (NULL);
	}
	nb = ft_nbdiese(str);
	ssqrt = ft_ssqrt(nb);
	dest = ft_destvalue(ssqrt);
	dest = ft_backtracking(tetri, dest, &ssqrt);
	return (dest);
}

int		main(int argc, char **argv)
{
	char	*str;
	char	*dest;

	if (ft_usage(argc) == 0)
		return (0);
	if(!(str = ft_convert(argv[1])))
	{
		ft_putendl(ERROR);
		return (0);
	}
	if (ft_is_valid(str) == 0)
		return (0);
	dest = ft_newdest(str);
	if (dest == NULL)
	{
		ft_putendl(ERROR);
		return (0);
	}
	else
		ft_putstr(dest);
	return (1);
}
