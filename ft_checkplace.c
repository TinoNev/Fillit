/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:22:45 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/16 13:56:02 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_checkpoint(char *dest, char *str, int i, int x)
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

static int		ft_checkposition(char *dest, char *str, int ssqrt, int x)
{
	int i;
	int tmp;
	int start;
	int max;

	i = -1;
	start = 0;
	tmp = x;
	max = x + ssqrt;
	while (str[++i] != '\0')
	{
		start = ft_startvalue(str, i, start);
		i = ft_ispoint(str, i);
		if (x <= max || (start == -1 && str[i - 1] == '.'))
		{
			if (ft_checkpoint(dest, str, i, x) == 0)
				return (0);
		}
		else if (ft_checkpoint(dest, str, i, x + start) == 0)
			return (0);
		str[i] == '\n' ? x = tmp + ssqrt : 0;
		str[i] == '\n' ? tmp = tmp + ssqrt + 1 : 0;
		x++;
	}
	return (1);
}

static int		ft_notpoint(char c, int x)
{
	while (c != '.' && c != '\0')
		x++;
	return (x);
}

int		ft_checkplace(char *dest, char *str, int ssqrt)
{
	int x;
	int i;

	i = 0;
	x = 0;
	while (dest[x] != '\0')
	{
		ft_notpoint(dest[x], x);
		if ((x == 0 || dest[x - 1] == '\n') && i == 0)
		{
			while (str[i] == '.')
			{
				x++;
				i++;
			}
		}
		if (ft_checkposition(dest, str, ssqrt, x) == 1)
			return (x);
		else
		{
			i = 0;
			x++;
		}
	}
	return (-1);
}

