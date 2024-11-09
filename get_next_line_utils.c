/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:35:40 by codespace         #+#    #+#             */
/*   Updated: 2024/11/08 13:25:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strchr(const char *s, int c)
{
    size_t  i;
    unsigned const char *str;
    unsigned char   letter;

    i = 0;
    str = (unsigned const char *)s;
    letter = (unsigned char)c;
    while (str[i])
    {
        if (str[i] == letter)
            return (char *)(s + i);
        i++;
    }
    if (letter == '\0')
        return (char *)(s + i);
    return (NULL);
}

char    *ft_strdup(const char *s)
{
    size_t  len;
    size_t  i;
    char    *dup;
    
    i = 0;
    len = ft_strlen(s);
    dup = (char *)malloc(sizeof(char) * len + 1);
    if (!dup)
        return (NULL);
    ft_strlcpy(dup, s, len + 1);
    return (dup);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *join;
    size_t  len1;
    size_t  len2;
    size_t  i;
    size_t  j;

    if(!s1 || !s2)
        return(NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    join = (char *)malloc(sizeof (char) * (len1 + len2 + 1));
    if (!join)
        return (NULL);
    i = 0;
    while (i < len1)
        join[i++] = s1[i];
    j = 0;
    while (j < len2)
    {
        join[i + j] = s2[j];
        j++;
    }
    join[i + j] = '\0';
    return (char *)join;
}

size_t ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    while (s[i])
        i++;
    return (i);
}

size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
    size_t srclen;
    size_t i;
    
    i = 0;
    srclen = ft_strlen(src);
    if (size == 0)
        return (srclen);
    while (i < (size -1) && src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (srclen);
}