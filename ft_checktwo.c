/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktwo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:56:35 by tlaberro          #+#    #+#             */
/*   Updated: 2017/12/15 10:56:37 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "include.h"

char    ft_charj(char *str)
{
    int i;

    i = 0;
    while (str[i] == '.')
        i++;
    return (str[i]);
}

char    *ft_upsizedest(char *dest, int ssqrt)
{
    ft_strdel(&dest);
    ft_destvalue(ssqrt);
    return (dest);
}

char    *ft_dellasttetri(char *dest, char c)
{
    int i;

    i = 0;
    while (dest[i] != '\0')
    {
        if (dest[i] == c)
            dest[i] = '.';
        i++;
    }
    return (dest);
}

int    ft_checkupdest(char *dest, int ssqrt)
{
    int x;
    int p;

    p = 0;
    x = 0;
    while (x < ssqrt)
    {
        if (dest[x] == '.')
            p++;
        x++;
    }
    if (p != ssqrt)
        return (1);
    else
        return (0);
}

int     ft_nexttetri(char **str, char *dest, int i)
{
    int j;
    int x;

    j = 0;
    x = 0;
    while (str[i]!= '\0')
    {
        if (str[i][j] >= 'A' && str[i][j] <= 'Z')
        {
            while (dest[x] != str[i][j] && dest[x] != '\0')
                    x++;
            if (dest[x] == '\0')
                return (i);
            else 
            {
                j = 0;
                x = 0;
            }
        }
        i++;
        j++;
    }
    return (-1);
}
/*
int     main(void)
{
    char **str;
    char *dest;
    char c;
    int x;

    x = 0;
    str = ft_ptrstr();
    str = ft_strvalue(str);
    str = ft_alphatetri(str);
    while (str[x] != '\0')
    {
        printf("%s\n", str[x]);
        x++;
    }
  
    //dest = ft_destvalue(6);
    //dest = ft_display(str, dest, 0, 6);
    //dest = ft_dellasttetri(dest, 'A');
    //x = ft_checkupdest(dest, 6);
   // printf("x = %d", x);
    //printf("%s", dest);
    return (0);
}
*/