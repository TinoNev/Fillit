/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:25:16 by lchaillo          #+#    #+#             */
/*   Updated: 2017/12/13 15:22:57 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "include.h"

char	**ft_ptrstr(void)
{
	char	**str;
	int		i;

	i = 0;
	if (!(str = (char **)malloc(sizeof(char *) * 20)))
		return (NULL);
	while (str[i])
	{
		str[i] = ft_strnew(20);
		++i;
	}
	return (str);
}

char	**ft_strvalue(char **str)
{
	str[0] = ".#..\n###.\n....\n....\n";
	str[1] = "###.\n.#..\n....\n....\n";
	str[2] = "#...\n##..\n#...\n....\n";
	str[3] = ".#..\n##..\n.#..\n....\n";
	str[4] = "#...\n#...\n#...\n#...\n";
	str[5] = "####\n....\n....\n....\n";
	str[6] = "##..\n.#..\n.#..\n....\n";
	str[7] = "##..\n#...\n#...\n....\n";
	str[8] = "..#.\n###.\n....\n....\n";
	str[9] = "#...\n###.\n....\n....\n";
	str[10] = "###.\n..#.\n....\n....\n";
	str[11] = "###.\n#...\n....\n....\n";
	str[12] = "#...\n#...\n##..\n....\n";
	str[13] = ".#..\n.#..\n##..\n....\n";
	str[14] = "##..\n.##.\n....\n....\n";
	str[15] = ".##.\n##..\n....\n....\n";
	str[16] = ".#..\n##..\n#...\n....\n";
	str[17] = "#...\n##..\n.#..\n....\n";
	str[18] = "##..\n##..\n....\n....\n";
	return (str);
}

char	*ft_destvalue(int ssqrt)
{
	char	*dest;
	int		i;
	int		len;
	int		p;

	len = (ssqrt * ssqrt) + ssqrt + 1;
	i = 0;
	p = 0;
	if (!(dest = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (i < len - 1)
	{
		dest[i] = '.';
		p++;
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
