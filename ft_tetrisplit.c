/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrisplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 10:25:17 by lchaillo          #+#    #+#             */
/*   Updated: 2017/12/04 15:34:37 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "include.h"

char	**ft_tetrisplit(char *str, int size)
{
	int		i;
	int		x;
	int		n;
	char	**tdest;

	x = 0;
	i = 19;
	n = 0;
	if (!(tdest = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		tdest[x] = ft_strsub(str, i - 19, (i - (i - 19)));
		x++;
		if (str[i + 1] == '\n')
			i = i + 20;
		++i;
	}
	tdest[x] = NULL;
	return (tdest);
}

char	**ft_tetricmp(char **s1, char **s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s2[j] && (ft_atoibin(s1[i]) % ft_atoibin(s2[j]) != 0))
			j++;
		if (s2[j] == '\0')
			s1[i] = ERROR;
		else
			s1[i] = ft_strcpy(s1[i], s2[j]);
		j = 0;
		i++;
	}
	return (s1);
}

char	**ft_alphatetri(char **str)
{
	int		i;
	int		s;
	char	a;

	s = 0;
	i = 0;
	a = 'A';
	while (str[i] != '\0')
	{
		while (str[i][s])
		{
			if (str[i][s] == '#')
				str[i][s] = a;
			s++;
		}
		a++;
		s = 0;
		i++;
	}
	return (str);
}
