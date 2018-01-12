/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:45:43 by lchaillo          #+#    #+#             */
/*   Updated: 2018/01/09 12:10:44 by tlaberro         ###   ########.fr       */
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

char	*ft_savechar(char *str, int len, char *c)
{
	int i;
	char *tmp;

	i = 0;
	i = ft_ispoint(str, i);
	if (c == 0)
	{
		ft_strdel(&c);
		c = ft_strnew(len);
		c[len - 1] = str[i];
		return (c);
	}
	else
	{
		tmp = ft_strdup(c);
		c = ft_strnew(len);
		c = ft_strcpy(c, tmp);
		free(tmp);
		c[len - 1] = str[i];
		return (c);
	}
}

char	*ft_dellastchar(char *c, int len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(c);
	c = ft_strnew(len);
	while (i < len)
	{
		c[i] = tmp[i];
		i++;
	}
	return (c);
}

int		ft_destchar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			return (1);
		++i;
	}
	return (0);
}
