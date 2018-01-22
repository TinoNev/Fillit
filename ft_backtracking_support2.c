/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking_support2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:14:17 by lchaillo          #+#    #+#             */
/*   Updated: 2018/01/22 10:16:47 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_del2(char **tetri, char *dest, t_v *v)
{
	v->x = ft_convertclen(tetri, v->c[v->len - 1]) + 1;
	v->len--;
	ft_dellasttetri(dest, v->c[v->len]);
	v->c = ft_dellastchar(v->c, v->len);
	v->i = 0;
	return (dest);
}

char		*ft_destchange2(char **tetri, char *dest, int ssqrt, t_v *v)
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
