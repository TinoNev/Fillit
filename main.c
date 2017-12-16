/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:46:32 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/05 18:14:41 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "include.h"

char	*ft_allerror(char *str)
{
	if (ft_regular(str) == OK && ft_fourdiese(str) == OK && ft_charonline(str)
			== OK && ft_count_line(str) == OK)
		return (OK);
	else
		return (ERROR);
}

char	**ft_tetri(char *str, int size)
{
	int	i;
	char **tetri;
	char **tab;

	i = 0;
	tab = ft_ptrstr();
	tab = ft_strvalue(tab);
	tetri = ft_tetrisplit(str, size);
	tetri = ft_tetricmp(tetri, tab);
	tetri = ft_alphatetri(tetri);
	while(tetri[i] != '\0')
	{
		printf("%s\n", tetri[i]);
		i++;
	}
	return (tetri);
}
char *ft_destvalue(int ssqrt);

int     ft_nexttetri(char **str, char *dest, int i);

int		main(int argc, char **argv)
{
	int		size;
	char 	*str;
	char    **tab;

	/*if (ft_usage(argc) == 0)
		return (0);
	*/
	size = ft_countsize(argv[1]);
	str = ft_convert(argv[1], size);
	//patapouf = ft_nbdiese(dest);
	size= ft_sizetetri(str);
	/*dest = ft_destvalue(ft_ssqrt(patapouf));
	if (ft_allerror(dest) == ERROR)
	{
		write(1, "error", 5);
		return (0);
	}*/
	tab = ft_tetri(str, size);
	//z = ft_nexttetri(tab, dest, 0);
	//printf("%d", z);
	return (0);
}
