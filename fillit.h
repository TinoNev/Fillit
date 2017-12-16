/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:41:42 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/16 11:42:20 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H
# define BUF_SIZE 5
# define ERROR "error"

# include <fcntl.h>
# include <unistd.h>
# include "Libft/libft.h"
# include <stdio.h> // A EFFACER AVANT DE RENDRE !!!!

int		ft_usage(int argc);
char	*ft_convert(char *file);
int		ft_valid_char(char *str);
int		ft_are_four(char *str);
int		ft_count_char(char *str);
int		ft_count_line(char *str);
int		ft_is_valid(char *str);
char	**ft_tabvalue(void);
int		ft_nbdiese(char *str);
int		ft_ssqrt(int nb);
char	*ft_destvalue(int ssqrt);

#endif
