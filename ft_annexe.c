/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:45:43 by lchaillo          #+#    #+#             */
/*   Updated: 2017/12/18 14:50:49 by lchaillo         ###   ########.fr       */
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

char	ft_savechar(char *dest)
{
	int len;

	len = ft_strlen(dest);
	while (len >= 0)
	{
		if (dest[len] >= 'A' && dest[len] <= 'Z')
			return (dest[len]);
		len--;
	}
	return (0);
}
