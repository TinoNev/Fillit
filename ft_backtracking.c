/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:10:46 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/18 14:58:58 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			ft_tablen(char **tetri)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	x = 0;
	c = 0;
	while (tetri[x] != '\0')
		x++;
	y = ft_ispoint(tetri[x - 1], y);
	c = tetri[x - 1][y];
	return (c);
}

static void		ft_initv(t_v *v)
{
	v->x = 0;
	v->i = 0;
	v->len = 0;
	v->temp = 0;
	v->c = ft_strnew(v->len);
}

static int		ft_ccmp(char *str, t_v *v)
{
	int		i;

	i = 0;
	i = ft_ispoint(str, i);
	if (v->c[v->len - 1] == str[i])
		return (1);
	else
		return (0);
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
			if (ft_ccmp(tetri[v->x], v) == 0)
			{
				v->len++;
				v->c = ft_savechar(tetri[v->x], v->len, v->c);
			}
			v->x = 0;
		}
		else
			v->x++;
	}
	return (dest);
}

char			*ft_backtracking(char **tetri, char *dest, int ssqrt)
{
	t_v *v;
	t_v v1;

	v = &v1;
	ft_initv(v);
	while (ft_checkupdest(dest, tetri) == 0)
	{
		dest = ft_firststep(tetri, dest, ssqrt, v);
		if (ft_checkupdest(dest, tetri) == 0)
		{
			ssqrt = ft_upssqrt(tetri, ssqrt, v, dest);
			dest = ft_destchange(tetri, dest, ssqrt, v);
			while (ft_nexttetri(tetri, dest, v->x) == -1 && v->len > 0)
			{
				ssqrt = ft_upssqrt(tetri, ssqrt, v, dest);
				dest = ft_destchange2(tetri, dest, ssqrt, v);
			}
		}
	}
	return (dest);
}
