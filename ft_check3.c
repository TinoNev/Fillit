/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:54:25 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/15 11:54:27 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "Libft/libft.h"

int     ft_nexttetri(char **str, char *dest, int i);
char    *ft_dellasttetri(char *dest, char c);
int    ft_checkupdest(char *dest, int ssqrt, char c);
char    *ft_upsizedest(char *dest, int ssqrt);

char    *ft_achievfillit(char **src, char *dest, int ssqrt)
{
    int i;
    int x;
    char c;
    int n;

    n = 0;
    i = 0;
    x = 0;
    c = 0;
    while (ft_nexttetri(src, dest, i) != -1)
    {
        i = ft_nexttetri(src, dest, i);
        x = ft_checkplacement(dest, src[i], ssqrt);
        if (x != -1)
        {
            ft_display(src[i], dest, x, ssqrt);
            n = i;
            i = 0;
            x = 0;
            c = ft_charj(src[i]);
        }
        else 
        {
            i++;
            if (src[i] == '\0')
            {
                ft_dellasttetri(dest, c);
                i = n + 1;
            }
        }
    }
    if (ft_checkupdest(dest, ssqrt, c) == 0)
        {
            ssqrt = ssqrt + 1;
            ft_upsizedest(dest, ssqrt);
            return (ft_achievfillit(src, dest, ssqrt));
        }
    return (dest);
}
