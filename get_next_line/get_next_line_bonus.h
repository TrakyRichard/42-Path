/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 05:37:53 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/28 04:11:23 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# ifndef FD_SIZE
#  define FD_SIZE 65535
# endif
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	char	*line;
	char	*next_buffer;
	int		line_chars_count;
	int		counter;
}	t_gnl;

char	*get_next_line(int fd);
void	ft_get_line(char *buffer, t_gnl *t_gnl);
char	*ft_read(char *res, int fd);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strcat(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_strdup(const char *s1);

#endif
