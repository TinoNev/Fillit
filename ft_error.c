/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:19:50 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/18 14:46:28 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_valid_char(char *str)
{
	int i;
	int size;

	i = 0;
	size = ft_strlen(str);
	while (str[i] != '\0' && str[i] == '.' | str[i] == '#' | str[i] == '\n')
	{
		i++;
	}
	if (i == size)
		return (1);
	else
		return (0);
}

int		ft_are_four(char *str)
{
	int i;
	int n;
	int d;

	d = 0;
	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			d++;
		if (str[i] == '\n')
			n++;
		if (n == 4)
		{
			if (d != 4)
				return (0);
			n = 0;
			d = 0;
			i++;
		}
		i++;
	}
	return (1);
}

int		ft_count_char(char *str)
{
	int i;
	int n;
	int c;

	i = 0;
	n = 0;
	c = 0;
	while (str[i] != '\0')
	{
		c++;
		if (str[i] == '\n')
		{
			n++;
			if (c != 5 && n < 5)
				return (0);
			c = 0;
			if (n == 5)
				n = 0;
		}
		i++;
	}
	return (1);
}

int		ft_count_line(char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	if (n == 4 || (n - 4) % 5 == 0)
		return (1);
	else
		return (0);
}
