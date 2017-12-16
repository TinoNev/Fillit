/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:12:18 by lchaillo          #+#    #+#             */
/*   Updated: 2017/12/16 11:47:02 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*str;
	char	**tab;
	char	*dest;
	int		ssqrt;

	if (ft_usage(argc) == 0)
		return (0);
	str = ft_convert(argv[1]);
	if (ft_is_valid(str) == 0)
		return (0);
	tab = ft_tabvalue();
	ssqrt = ft_ssqrt(ft_nbdiese(str));
	dest = ft_destvalue(ssqrt);
	return (1);
}
