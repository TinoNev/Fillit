/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking_support.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:07:00 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/18 14:59:45 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_del(char **tetri, char *dest, t_v *v, int ssqrt)
{
	v->x = ft_convertclen(tetri, v->c[v->len - 1]);
	ft_dellasttetri(dest, v->c[v->len - 1]);
	if (ft_checkplace(dest, tetri[v->x], ssqrt, v->temp + 1) == -1)
	{
		v->len--;
		v->c = ft_dellastchar(v->c, v->len);
		v->temp = ft_tempvalue(tetri[v->x], dest);
		v->x++;
		v->i = 0;
	}
	else
	{
		v->temp++;
		v->i = v->temp;
	}
	return (dest);
}

char	*ft_del2(char **tetri, char *dest, t_v *v)
{
	v->x = ft_convertclen(tetri, v->c[v->len - 1]) + 1;
	v->len--;
	ft_dellasttetri(dest, v->c[v->len]);
	v->c = ft_dellastchar(v->c, v->len);
	v->i = 0;
	return (dest);
}

int		ft_upssqrt(char **tetri, int ssqrt, t_v *v, char *dest)
{
	if ((v->len == 1 && v->c[0] == ft_tablen(tetri)) ||
			ft_checkpoint2(dest) == 1)
		ssqrt = ssqrt + 1;
	return (ssqrt);
}

char	*ft_destchange(char **tetri, char *dest, int ssqrt, t_v *v)
{
	if ((v->len == 1 && v->c[0] == ft_tablen(tetri)) ||
			ft_checkpoint2(dest) == 1)
	{
		dest = ft_upsizedest(dest, ssqrt);
		v->len = 0;
		v->c = ft_strnew(v->len);
		v->x = 0;
		v->i = 0;
	}
	else
		dest = ft_del(tetri, dest, v, ssqrt);
	return (dest);
}

char	*ft_destchange2(char **tetri, char *dest, int ssqrt, t_v *v)
{
	if ((v->len == 1 && v->c[0] == ft_tablen(tetri)) ||
			ft_checkpoint2(dest) == 1)
	{
		dest = ft_upsizedest(dest, ssqrt);
		v->len = 0;
		v->c = ft_strnew(v->len);
		v->x = 0;
		v->i = 0;
	}
	else
		dest = ft_del2(tetri, dest, v);
	return (dest);
}
