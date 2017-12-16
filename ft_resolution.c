/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:51:19 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/07 11:22:29 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "include.h"

char	*ft_putn(char *str, int sqrt)
{
	int i;

	i = sqrt + 1;
	while (i <= (sqrt * sqrt) + sqrt)
	{
		str[i] = '\n';
		if (i + 1 <= (sqrt * sqrt) + sqrt)
			i = i + sqrt;
		else
			i++;
	}
	return (str);
}

char	*ft_resolution(char **str, int sqr, char *dest)
{
	int i;
	int x;
	int j;

	i = 0;
	x = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			while (str[i][j] == '.')
				j++;
			if (str[i][j] == '\n')
			{
				j++;
				while (dest[x] != '\n' && dest[x] != '\0')
					x++;
				//dest[x] == '\n' ? x++ : 0;
				if (dest[x] == '\n')
				{
					x++;
				}
			}
			//dest[x] >= 'A' && dest[x] <= 'Z' ? x++ : 0;
			if (dest[x] >= 'A' && dest[x] <= 'Z')
			{
				x++;
			}
			dest[x] = str[i][j];
			x++;
			j++;
		}
		j = 0;
		x = 0;
		i++;
	}
	return (dest);
}
