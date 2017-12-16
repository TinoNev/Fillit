/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:41:42 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/12 12:08:59 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# define BUF_SIZE 5

# include <stdio.h>
# define ERROR "error"
# define OK "ok"
# include <fcntl.h>
# include <unistd.h>

char	*ft_resolution(char **str, int sqrt, char *dest);
char	*ft_regular(char *str);
char	*ft_fourdiese(char *str);
char	*ft_charonline(char *str);
char	*ft_count_line(char *str);
int		ft_usage(int argc);
int		ft_countsize(char *file);
char	*ft_convert(char *file, int size);
int		ft_sizetetri(char *str);
int		ft_atoibin(char *str);
char	**ft_tetrisplit(char *str, int size);
char	**ft_ptrstr(void);
char	**ft_strvalue(char **str);
char	**ft_tetricmp(char **s1, char **s2);
char	**ft_alphatetri(char **str);
int		ft_nbdiese(char *str);
int		ft_ssqrt(int nb);
int		ft_jvalue(char *src, int i, int j);
int		ft_ispoint(char *src, int i);
char	*ft_destcpy(char *src, char *dest, int x, int i);
char	*ft_display(char *src, char *dest, int x, int ssqrt);
char    *ft_destvalue(int ssqrt);
int		ft_checkplacement(char *dest, char *str, int ssqrt);
char    ft_charj(char *str);

#endif
