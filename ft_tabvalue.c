/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:25:16 by lchaillo          #+#    #+#             */
/*   Updated: 2017/12/16 11:48:02 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_tabnew(void)
{
	char	**tab;
	int		x;

	x = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * 20)))
		return (NULL);
	while (tab[x])
	{
		tab[x] = ft_strnew(20);
		++x;
	}
	return (tab);
}

char			**ft_tabvalue(void)
{
	char **tab;

	tab = ft_tabnew();
	tab[0] = ".#..\n###.\n....\n....\n";
	tab[1] = "###.\n.#..\n....\n....\n";
	tab[2] = "#...\n##..\n#...\n....\n";
	tab[3] = ".#..\n##..\n.#..\n....\n";
	tab[4] = "#...\n#...\n#...\n#...\n";
	tab[5] = "####\n....\n....\n....\n";
	tab[6] = "##..\n.#..\n.#..\n....\n";
	tab[7] = "##..\n#...\n#...\n....\n";
	tab[8] = "..#.\n###.\n....\n....\n";
	tab[9] = "#...\n###.\n....\n....\n";
	tab[10] = "###.\n..#.\n....\n....\n";
	tab[11] = "###.\n#...\n....\n....\n";
	tab[12] = "#...\n#...\n##..\n....\n";
	tab[13] = ".#..\n.#..\n##..\n....\n";
	tab[14] = "##..\n.##.\n....\n....\n";
	tab[15] = ".##.\n##..\n....\n....\n";
	tab[16] = ".#..\n##..\n#...\n....\n";
	tab[17] = "#...\n##..\n.#..\n....\n";
	tab[18] = "##..\n##..\n....\n....\n";
	return (tab);
}

char			*ft_destvalue(int ssqrt)
{
	char	*dest;
	int		i;
	int		len;

	len = (ssqrt * ssqrt) + ssqrt + 1;
	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (i < len - 1)
	{
		dest[i] = '.';
		i++;
	}
	i = ssqrt;
	while (i < len - 1)
	{
		dest[i] = '\n';
		i + 1 < len - 1 ? i = i + ssqrt : 0;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
