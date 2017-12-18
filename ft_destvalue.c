/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destvalue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:27:08 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/18 11:27:11 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_nbdiese(char *str)
{
	int i;
	int d;

	i = 0;
	d = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			d++;
		i++;
	}
	return (d);
}

int		ft_ssqrt(int nb)
{
	int i;

	i = 2;
	while (i * i < nb)
		i++;
	if (i * i > nb)
		return (ft_ssqrt(nb + 1));
	else
		return (i);
}

char	*ft_destvalue(int ssqrt)
{
	char	*dest;
	int		i;
	int		len;

	len = ssqrt * ssqrt + ssqrt + 1;
	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (i < len - 1)
	{
		dest[i] = '.';
		++i;
	}
	i = ssqrt;
	while (i < len - 1)
	{
		dest[i] = '\n';
		i + 1 < len - 1 ? i = i + ssqrt : 0;
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_upsizedest(char *dest, int ssqrt)
{
	ft_strdel(&dest);
	ft_destvalue(ssqrt);
	return (dest);
}
