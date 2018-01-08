/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 10:50:47 by lchaillo          #+#    #+#             */
/*   Updated: 2018/01/08 11:03:01 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_usage(int argc)
{
	char	*usage;

	usage = "usage : fillit source_file";
	if (argc != 2)
	{
		ft_putendl(usage);
		return (0);
	}
	return (1);
}

int		ft_is_valid(char *str)
{
	if (ft_valid_char(str) == 0 || ft_are_four(str) == 0 || ft_error(str) == 0
			|| ft_count_char(str) == 0 || ft_count_line(str) == 0)
	{
		ft_putendl(ERROR);
		return (0);
	}
	return (1);
}
