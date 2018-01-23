/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking_support.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:07:00 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/23 13:48:32 by lchaillo         ###   ########.fr       */
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

int			ft_checkpoint2(char *dest)
{
	int i;

	i = 0;
	while (dest[i] == '.' || dest[i] == '\n')
		i++;
	if (dest[i] == '\0')
		return (1);
	else
		return (0);
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
	if (ft_checkplace(dest, tetri[v->x], *ssqrt, v->temp + 1) == -1)
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

int			ft_upssqrt(char **tetri, int ssqrt, t_v *v, char *dest)
{
	if (ft_checkplace(dest, tetri[0], ssqrt, v->temp + 1) == -1 && v->x == 0)
		++ssqrt;
	return (ssqrt);
}
