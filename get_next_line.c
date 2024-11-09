/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:35:15 by codespace         #+#    #+#             */
/*   Updated: 2024/11/09 11:06:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *reminder;
    char buffer[BUFFER_SIZE + 1];
    char    *line;
    char    *new_linepos;
    size_t  line_length;
    size_t  remain_length; 
    ssize_t bytes_read;

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read <= 0)
        return (NULL);
    buffer[bytes_read] = '\0';
    
    new_linepos = ft_strchr(buffer, '\n');
    if (new_linepos != NULL)
    {
        line_length = new_linepos - buffer + 1;
        line = (char *)malloc(line_length + 1);
        if (!line)
            return (NULL);
        ft_strlcpy(line, buffer, line_length);
        remain_length = bytes_read - line_length;
        if (remain_length > 0)
        {
            free (reminder);
            reminder = ft_strdup(new_linepos + 1);
        }
        else
            reminder = NULL;
    }
    else
    {
       line = ft_strdup(buffer);
       free (reminder);
       reminder = NULL; 
    }
    return (line);
}