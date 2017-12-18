/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:12:18 by lchaillo          #+#    #+#             */
/*   Updated: 2017/12/18 11:41:23 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_puttab(char **tetri)
{
	int	x;

	x = 0;
	while (tetri[x] != '\0')
	{
		printf("%s\n", tetri[x]);
		x++;
	}
}

char	*ft_newdest(char *str)
{
	int		ssqrt;
	char	*dest;
	int		nb;
	char	**tetri;
	int		n;

	tetri = ft_tetrinew(str);
	nb = ft_nbdiese(str);
	ssqrt = ft_ssqrt(nb);
	dest = ft_destvalue(ssqrt);
	dest = ft_backtracking(tetri, dest, ssqrt);
	printf("%s", dest);
	return (dest);
}

int		main(int argc, char **argv)
{
	char *str;
	char *dest;

	if (ft_usage(argc) == 0)
		return (0);
	str = ft_convert(argv[1]);
	if (ft_is_valid(str) == 0)
		return (0);
	dest = ft_newdest(str);
	return (1);
}
