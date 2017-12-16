/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:22:45 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/13 17:17:57 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "Libft/libft.h"

static int		ft_checkposition(char *dest, char *str, int i, int x)
{
	if (str[i] >= 'A' && str[i] <= 'Z')
	{
		if (dest[x] == '.')
			return (1);
		else
			return (0);
	}
	return (1);
}

static int		ft_checkdisplay(char *dest, char *str, int ssqrt, int x)
{
	int i;
	int n;
	int j;
	int tmp;

	i = -1;
	j = 0;
	n = x;
	tmp = x + ssqrt;
	while (str[++i] != '\0')
	{
		j = ft_jvalue(str, i, j);
		i = ft_ispoint(str, i);
		if (x <= tmp || (j == -1 && str[i - 1] == '.'))
		{
			if (ft_checkposition(dest, str, i, x) == 0)
				return (0);
		}
		else if (ft_checkposition(dest, str, i, x + j) == 0)
			return (0);
		str[i] == '\n' ? x = n + ssqrt : 0;
		str[i] == '\n' ? n = n + ssqrt + 1 : 0;
		x++;
	}
	return (1);
}

static int		ft_xposition(char c, int x)
{
	while (c != '.' && c != '\0')
		x++;
	return (x);
}

int		ft_checkplacement(char *dest, char *str, int ssqrt)
{
	int x;
	int i;

	i = 0;
	x = 0;
	while (dest[x] != '\0')
	{
		ft_xposition(dest[x], x);
		if ((x == 0 || dest[x - 1] == '\n') && i == 0)
		{
			while (str[i] == '.')
			{
				x++;
				i++;
			}
		}
		if (ft_checkdisplay(dest, str, ssqrt, x) == 1)
			return (x);
		else
		{
			i = 0;
			x++;
		}
	}
	return (-1);
}

