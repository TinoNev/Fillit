/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:24:53 by tlaberro          #+#    #+#             */
/*   Updated: 2018/01/22 10:16:35 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 5
# define ERROR "error"

# include <fcntl.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct		s_variable
{
	int		x;
	int		i;
	int		len;
	int		temp;
	char	*c;
}					t_v;

int					ft_usage(int argc);
int					ft_count_size(char *file);
char				*ft_convert(char *file, int size);
int					ft_valid_char(char *str);
int					ft_are_four(char *str);
int					ft_count_char(char *str);
int					ft_count_line(char *str);
int					ft_is_valid(char *str);
char				**ft_tabvalue(void);
int					ft_nbdiese(char *str);
int					ft_ssqrt(int nb);
char				*ft_destvalue(int ssqrt);
int					ft_atoibin(char *str);
char				**ft_tetrinew(char *str);
int					ft_startvalue(char *src, int i, int start);
int					ft_ispoint(char *src, int i);
int					ft_checkplace(char *dest, char *str, int ssqrt, int x);
char				*ft_display(char *src, char *dest, int x, int ssqrt);
char				*ft_savechar(char *str, int len, char *c);
char				*ft_dellastchar(char *c, int len);
char				*ft_upsizedest(char *dest, int ssqrt);
char				*ft_dellasttetri(char *dest, char c);
int					ft_checkupdest(char *dest, char **tetri);
int					ft_nexttetri(char **tetri, char *dest, int x);
char				*ft_backtracking(char **tetri, char *dest, int ssqrt);
int					ft_convertclen(char **tetri, char c);
char				ft_tablen(char **tetri);
int					ft_upssqrt(char **tetri, int ssqrt, t_v *v, char *dest);
char				*ft_destchange(char **tetri, char *dest, int ssqrt, t_v *v);
int					ft_sizetetri(char *str);
char				**ft_tetrisplit(char *str, int size);
char				*ft_destchange2(char **tetri, char *dest,
										int ssqrt, t_v *v);
int					ft_checkpoint2(char *dest);

#endif
