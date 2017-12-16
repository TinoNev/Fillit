/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:18:03 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/12 12:00:08 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "Libft/libft.h"

int		ft_jvalue(char *src, int i, int j)
{
	if (j == 0)
	{
		if (i == 0)
		{
			while (src[i] == '.')
			{
				j--;
				i++;
			}
		}
		else if (src[i - 1] == '\n')
		{
			while (src[i] == '.')
			{
				j++;
				i++;
			}
		}
	}
	return (j);
}

int		ft_ispoint(char *src, int i)
{
	while (src[i] == '.')
		i++;
	return (i);
}

char	*ft_destcpy(char *src, char *dest, int x, int i)
{
	if (src[i] >= 'A' && src[i] <= 'Z')
	{
		dest[x] = src[i];
	}
	return (dest);
}

char	*ft_display(char *src, char *dest, int x, int ssqrt)
{
	int i;
	int n;
	int j;

	i = 0;
	j = 0;
	n = x;
	while (src[i] != '\0')
	{
		j = ft_jvalue(src, i, j);
		i = ft_ispoint(src, i);
		if (x < ssqrt || (j == -1 && src[i - 1] == '.'))
			dest = ft_destcpy(src, dest, x, i);
		else
			dest = ft_destcpy(src, dest, x + j, i);
		if (src[i] == '\n')
		{
			x = n + ssqrt;
			n = n + ssqrt + 1;
		}
		x++;
		i++;
	}
	return (dest);
}
