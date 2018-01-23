/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking_support.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:07:00 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/23 14:37:56 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_tempvalue(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	i = ft_ispoint(s1, i);
	while (s1[i] != s2[j])
		j++;
	return (j);
}

char	*ft_del(char **tetri, char *dest, t_v *v, int *ssqrt)
{
	v->temp = ft_tempvalue(tetri[v->x], dest);
	ft_dellasttetri(dest, tetri[v->x]);
	if (ft_checkplace(dest, tetri[0], *ssqrt, v->temp + 1) == -1 && v->x == 0)
	{
		(*ssqrt)++;
		dest = ft_upsizedest(dest, *ssqrt);
		v->x = 0;
		v->i = 0;
		v->temp = 0;
	}
	else if (ft_checkplace(dest, tetri[v->x], *ssqrt, v->temp + 1) == -1)
	{
		v->x--;
		v->temp = ft_tempvalue(tetri[v->x], dest);
		v->i = 0;
		return (ft_del(tetri, dest, v, ssqrt));
	}
	else
	{
		v->temp++;
		v->i = v->temp;
	}
	return (dest);
}
