/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:45:43 by lchaillo          #+#    #+#             */
/*   Updated: 2018/01/23 13:52:39 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_startvalue(char *src, int i, int start)
{
	if (start == 0)
	{
		if (i == 0)
		{
			while (src[i] == '.')
			{
				start--;
				i++;
			}
		}
		else if (src[i - 1] == '\n')
		{
			while (src[i] == '.')
			{
				start++;
				i++;
			}
		}
	}
	return (start);
}

int		ft_ispoint(char *src, int i)
{
	while (src[i] == '.')
		++i;
	return (i);
}
