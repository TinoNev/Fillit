/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:54:08 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/04 11:06:22 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "include.h"

int		ft_sizetetri(char *str)
{
	int i;
	int m;
	int size;

	size = 0;
	i = 0;
	m = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			m++;
		i++;
	}
	size = (i - m) / 16;
	return (size);
}

int		ft_atoibin(char *str)
{
	int i;
	int b;
	int count_n;

	i = 0;
	b = 0;
	count_n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			count_n++;
		if (str[i] == '#')
			b = b | (1 << (i - count_n));
		if (str[i] == '.')
			b = b & ~(0 << (i - count_n));
		i++;
	}
	return (b);
}
