/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:40:01 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/04 15:40:03 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "include.h"

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
