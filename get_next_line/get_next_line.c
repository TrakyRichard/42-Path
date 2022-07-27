/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 05:19:26 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/27 10:37:57 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_read(char *res, int fd)
{
	size_t byte_readed;
	char *buffer;

	byte_readed = 1;
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (byte_readed != 0 && !ft_strchr(buffer, '\n'))
	{
		byte_readed = read(fd, buffer, BUFFER_SIZE);
		if (byte_readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_readed] = '\0';
		res = ft_strjoin(res, buffer);
	}
	free(buffer);
	return (res);
}

t_gnl ft_get_line(char *buffer, t_gnl *t_gnl)
{
	int line_counter;
	int counter;

	line_counter = 0;
	counter = 0;
	while (buffer[line_counter] != '\n' && buffer[line_counter] != '\0')
		line_counter++;
	t_gnl->line = ft_calloc(line_counter + 1, sizeof(char));
	if (t_gnl->line == NULL)
		return (*t_gnl);
	while (line_counter > counter)
	{
		t_gnl->line[counter++] = *buffer;
		buffer++;
	}
	if (*buffer != '\0' )
		buffer++;
	t_gnl->line[counter] = '\0';
	t_gnl->next_buffer = buffer;
	return (*t_gnl);
}

char *get_next_line(int fd)
{
	static char *buffer;
	t_gnl t_gnl;
	t_gnl.line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(buffer, fd);
	if (!buffer)
		return (NULL);
	t_gnl.next_buffer = buffer;

	ft_get_line(buffer, &t_gnl);
	if (t_gnl.line == NULL)
		return (NULL);
	buffer = t_gnl.next_buffer;
	return (t_gnl.line);
}
