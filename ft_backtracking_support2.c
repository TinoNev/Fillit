/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking_support2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:50:03 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/18 14:58:40 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_tempvalue(char *s1, char *s2)
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

int		ft_checkpoint2(char *dest)
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
