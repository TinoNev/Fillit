/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:10:46 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/15 19:25:47 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		ft_tablen(char **tetri)
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
	v->c = ft_strnew(v->len);
}

static char		*ft_firststep(char **tetri, char *dest, int ssqrt, t_v *v)
{
	while (ft_nexttetri(tetri, dest, v->x) != -1)
	{
		v->x = ft_nexttetri(tetri, dest, v->x);
		v->i = ft_checkplace(dest, tetri[v->x], ssqrt);
		if (v->i != -1)
		{
			dest = ft_display(tetri[v->x], dest, v->i, ssqrt);
			v->i = 0;
			v->len++;
			v->c = ft_savechar(tetri[v->x], v->len, v->c);
			v->x = 0;
		}
		else
			v->x++;
	}
	return (dest);
}

static char		*ft_del(char **tetri, char *dest, t_v *v)
{
	v->x = ft_convertclen(tetri, v->c[v->len - 1]) + 1;
	v->len--;
	ft_dellasttetri(dest, v->c[v->len]);
	v->c = ft_dellastchar(v->c, v->len);
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
		ft_putendl(dest);
		if (ft_checkupdest(dest, tetri) == 0)
		{
			if (v->len == 1 && v->c[0] == ft_tablen(tetri))
			{
				ssqrt = ssqrt + 1;
				dest = ft_upsizedest(dest, ssqrt);
				return (ft_backtracking(tetri, dest, ssqrt));
			}
			dest = ft_del(tetri, dest, v);
			if (ft_nexttetri(tetri, dest, v->x) == -1 && v->len > 0)
			{
				if (v->len == 1 && v->c[0] == ft_tablen(tetri))
				{
					ssqrt = ssqrt + 1;
					dest = ft_upsizedest(dest, ssqrt);
					return (ft_backtracking(tetri, dest, ssqrt));
				}
				dest = ft_del(tetri, dest, v);
			}
		}
	}
	return (dest);
}
