/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:35:40 by codespace         #+#    #+#             */
/*   Updated: 2024/11/16 15:05:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
    dup = (char *)malloc(sizeof(char) * (len + 1));
    if (!dup)
        return (NULL);
    while (i < len) {
        dup[i] = s[i];
        i++;
    }
    dup[len] = '\0';
    return (dup);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *join;
    size_t  len1;
    size_t  len2;
    size_t  i;
    size_t  j;

    //if(!s1 && !s2)
    if(!s1 || !s2)
        return(NULL);
    //if (!s1)
        //return(ft_strdup(s2));
    //if (!s2)
        //return (ft_strdup(s1));
    //printf("Joining: \"%s\" + \"%s\"\n", s1, s2);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    join = (char *)malloc(sizeof (char) * (len1 + len2 + 1));
    if (!join)
        return (NULL);
    i = 0;
    while (i < len1)
        join[i++] = *s1++;
    j = 0;
    while (j < len2)
        join[i + j++] = *s2++;
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

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *sstr;
    size_t i;
    
    i = 0;
    if (!s)
        return (NULL);
    if (ft_strlen(s) < start)
        len = 0;
    if (ft_strlen(s) - start < len)
        len = ft_strlen(s) - start;
    sstr = (char *)malloc(sizeof(char) * (len + 1));
    if(!sstr)
        return (NULL);
    while (i < len)
    {
        sstr[i++] = s[start++];
    }
    sstr[i] = '\0';
    return (char *)sstr; 
}
