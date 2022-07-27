/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 05:37:53 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/27 10:01:43 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_gnl
{
	char *line;
	char *next_buffer;
} t_gnl;

char *get_next_line(int fd);
t_gnl ft_get_line(char *buffer, t_gnl *t_gnl);
static char *ft_read(char *res, int fd);
char *ft_strcpy(char *dst, char *src);
char *ft_strcat(char *s1, char *s2);
char *ft_strjoin(char *s1, char *s2);
char *ft_calloc(size_t count, size_t size);
int ft_has_new_line(char *str);
char *ft_strchr(char *s, int c);
size_t ft_strlen(char *s);

#endif
