/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:10:46 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/23 14:38:47 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_initv(t_v *v)
{
	v->x = 0;
	v->i = 0;
	v->temp = 0;
	v->mem = 0;
}

static char		*ft_firststep(char **tetri, char *dest, int ssqrt, t_v *v)
{
	while (ft_nexttetri(tetri, dest, v->x) != -1)
	{
		v->x = ft_nexttetri(tetri, dest, v->x);
		v->i = ft_checkplace(dest, tetri[v->x], ssqrt, v->i);
		if (v->i != -1)
		{
			dest = ft_display(tetri[v->x], dest, v->i, ssqrt);
			v->temp = v->i;
			v->i = 0;
			v->mem = v->x;
			v->x = 0;
		}
		else
			v->x++;
	}
	return (dest);
}

static int	ft_checkpoint2(char *dest)
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

char			*ft_backtracking(char **tetri, char *dest, int *ssqrt)
{
	t_v *v;
	t_v v1;

	v = &v1;
	ft_initv(v);
	while (ft_checkupdest(dest, tetri) == 0)
	{
		dest = ft_firststep(tetri, dest, *ssqrt, v);
		if (ft_checkupdest(dest, tetri) == 0)
		{
			v->x = v->mem;
			if (ft_checkpoint2(dest) == 1)
			{
				(*ssqrt)++;
				dest = ft_upsizedest(dest, *ssqrt);
				v->x = 0;
				v->i = 0;
				v->temp = 0;
			}
			else
				dest = ft_del(tetri, dest, v, ssqrt);
		}
	}
	return (dest);
}
