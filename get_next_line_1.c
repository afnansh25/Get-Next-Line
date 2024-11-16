/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:35:15 by codespace         #+#    #+#             */
/*   Updated: 2024/11/16 12:49:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char    *read_to_buffer(int fd, char *reminder)
{
    char    buffer[BUFFER_SIZE + 1];
    char    *new_reminder;
    ssize_t bytes_read;
    
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == 0) {
        printf("End of file reached\n");
        return NULL;  // Return current reminder if EOF
    }
    if (bytes_read < 0) {
        perror("Error reading from file");
        free(reminder);
        return NULL;  // Return NULL on read error
    }
    // if (bytes_read <= 0)
    //     return (reminder);
    buffer[bytes_read] = '\0'; 
    printf("Read %ld bytes: \"%s\"\n", bytes_read, buffer);
    printf("Before joining: reminder=\"%s\", buffer=\"%s\"\n", reminder, buffer);
    new_reminder = ft_strjoin(reminder, buffer);
    printf("After joining: new_reminder=\"%s\"\n", new_reminder);
    free(reminder);
    return (new_reminder);
}

char    *extract_line(char  *reminder)
{
    char    *newline_pos;
    char    *line;
    size_t  line_lenght;

    if (!reminder || *reminder == '\0') // Handle empty or NULL reminder
        return NULL;
    newline_pos = ft_strchr(reminder, '\n');
    if (newline_pos)
        line_lenght = newline_pos - reminder + 1;
    else
        line_lenght = ft_strlen(reminder);
    printf("Extracting line of length %zu\n", line_lenght);
    line = ft_substr(reminder, 0, line_lenght);
    return (line);
}

char    *update_reminder(char   *reminder)
{
    char    *newline_pos;
    char    *new_reminder;
    
    newline_pos = ft_strchr(reminder, '\n');
    if (!newline_pos)
    {
        free(reminder);
        return (NULL);
    }
    new_reminder = ft_strdup(newline_pos + 1);
    if (!new_reminder) {
        free(reminder);
        return NULL;     // Memory allocation failure
    }
    free (reminder);
    return (new_reminder);
}

char    *get_next_line(int fd)
{
    static char *reminder;
    char    *line;
    char    *newline_pos;
    
    if (!reminder) //If reminder is NULL (uninitialized), do the following
    {
        reminder = ft_strdup(""); //Initialize reminder as an empty string by duplicating "" (an empty string)
        if (!reminder)
            return NULL; //If reminder failed to allocate memory, return NULL to indicate an error.
    }
    newline_pos = ft_strchr(reminder, '\n'); //"Look for the first occurrence of a newline (\n) in reminder. 
    //If found, newline_pos will point to its position. If not found, newline_pos will be NULL."
    while(!newline_pos) //"If there’s no newline character (newline_pos == NULL), keep looping to read more data from the file."
    {
        printf("Looping to read more data because no newline found\n");
        reminder = read_to_buffer(fd, reminder); //Read more data from the file descriptor fd and add it to the reminder string. Update reminder with the new content.
        if(!reminder) //If read_to_buffer returned NULL, it means there’s no more data to read (end of file) or an error occurred.
        {
            if(!reminder || *reminder == '\0')//If reminder is empty (\0), return NULL to indicate there’s no more data to process (end of file)
                return (NULL);
            line = reminder; //Take the remaining content of reminder as the final line (since there’s no newline character)
            reminder = NULL;//Clear the reminder variable by setting it to NULL so it doesn’t hold old data for future calls.
            return (line);//Return the remaining content of reminder as the last line in the file.
        }
        newline_pos = ft_strchr(reminder, '\n'); //After reading more data, check again for a newline character (\n) in the updated reminder. Update newline_pos with its position if found, or NULL if no newline exists.
    }
    line = extract_line(reminder);
    printf("Returning line: \"%s\"\n", line);
    reminder = update_reminder(reminder);
    return (line);
}