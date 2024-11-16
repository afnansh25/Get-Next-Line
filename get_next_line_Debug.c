/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:35:15 by codespace         #+#    #+#             */
/*   Updated: 2024/11/16 14:49:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>

char *read_to_buffer(int fd, char *reminder) 
{
    char buffer[BUFFER_SIZE + 1];
    char *new_reminder;
    ssize_t bytes_read;

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    //printf("Read %zd bytes: \"%s\"\n", bytes_read, buffer);
    if (bytes_read <= 0)
        return (NULL);
    buffer[bytes_read] = '\0';
    //printf("Before joining: reminder=\"%s\", buffer=\"%s\"\n", reminder, buffer);
    new_reminder = ft_strjoin(reminder, buffer);
    //printf("After joining: new_reminder=\"%s\"\n", new_reminder);
    free(reminder);
    return (new_reminder);
}

char *extract_line(char *reminder) 
{
    char *newline_pos;
    char *line;
    size_t line_length;

    if (!reminder || *reminder == '\0')
        return (NULL);
    newline_pos = ft_strchr(reminder, '\n');
    if (newline_pos)
        line_length = newline_pos - reminder + 1;
    else
        line_length = ft_strlen(reminder);
    line = ft_substr(reminder, 0, line_length);
    if (!line)
        return NULL;
    return (line);
}

char *update_reminder(char *reminder) 
{
    char *newline_pos;
    char *new_reminder;

    newline_pos = ft_strchr(reminder, '\n');
    if (!newline_pos) {
        free(reminder);
        return (NULL);
    }
    if (*(newline_pos + 1) == '\0') 
    {
        free(reminder);
        return NULL;
    }
    new_reminder = ft_strdup(newline_pos + 1);
    if (!new_reminder) {
        free(reminder);
        return NULL;
    }
    free(reminder);
    return (new_reminder);
}

char *get_next_line(int fd) 
{
    static char *reminder;
    char *line;
    char *newline_pos;

    if (!reminder) {
        reminder = ft_strdup("");
        if (!reminder)
            return (NULL);
    }
    newline_pos = ft_strchr(reminder, '\n');
    while (!newline_pos) {
        //printf("Before read_to_buffer: reminder=\"%s\"\n", reminder);
        reminder = read_to_buffer(fd, reminder);
        if (!reminder)
            return (NULL);
        //printf("After read_to_buffer: reminder=\"%s\"\n", reminder);
        newline_pos = ft_strchr(reminder, '\n');
    }
    line = extract_line(reminder);
    //printf("Extracted line: \"%s\"\n", line);
    //printf("Final reminder before update: \"%s\"\n", reminder);
    reminder = update_reminder(reminder);
    //printf("Updated reminder: \"%s\"\n", reminder);
    return (line);
}
