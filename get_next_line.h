/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:38:21 by codespace         #+#    #+#             */
/*   Updated: 2024/11/16 14:55:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define BUFFER_SIZE 1
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlen(const char *s);
char    *ft_substr(char const *s, unsigned int start, size_t len);

#endif
