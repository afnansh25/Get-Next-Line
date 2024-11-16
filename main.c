/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:21:54 by codespace         #+#    #+#             */
/*   Updated: 2024/11/16 14:59:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>  // For open function
#include <stdio.h>  // For printf
#include <unistd.h> // For close function

int main() {
    int fd = open("sample.txt", O_RDONLY); // Open a file in read-only mode
    if (fd == -1) {
        printf("Failed to open file\n");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);  // Remember to free the line after printing
    }
    close(fd);  // Close the file descriptor
    return 0;
}
