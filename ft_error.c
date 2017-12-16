/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:19:50 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/01 16:10:39 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "include.h"

char	*ft_regular(char *str)
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
		return (OK);
	else
		return (ERROR);
}

int		ft_usage(int argc)
{
	char *usage;

	usage = "usage : fillit source_file";
	if (argc != 2)
	{
		write(1, usage, ft_strlen(usage));
		write(1, "\n", 1);
		return (0);
	}
	return (1);
}

char	*ft_fourdiese(char *str)
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
				return (ERROR);
			n = 0;
			d = 0;
			i++;
		}
		i++;
	}
	return (OK);
}

char	*ft_charonline(char *str)
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
				return (ERROR);
			c = 0;
			if (n == 5)
				n = 0;
		}
		i++;
	}
	return (OK);
}

char	*ft_count_line(char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			n++;
			if (n == 4)
			{
				if (str[i + 1] == '\n' || str[i + 1] == '\0')
				{
					i++;
					n = 0;
				}
				else
					return (ERROR);
			}
		}
		i++;
	}
	return (OK);
}
