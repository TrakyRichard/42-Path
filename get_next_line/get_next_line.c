/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 05:19:26 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/28 05:49:19 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *res, int fd)
{
	size_t	byte_readed;
	char	*buffer;

	byte_readed = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (byte_readed != 0 && !ft_strchr(res, '\n'))
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

void	ft_get_line(char *buffer, t_gnl *t_gnl)
{
	while (buffer[t_gnl->line_chars_count] != '\n' \
		&& buffer[t_gnl->line_chars_count] != '\0')
		t_gnl->line_chars_count++;
	t_gnl->line = malloc(t_gnl->line_chars_count + 2 * sizeof(char));
	if (t_gnl->line == NULL)
		return ;
	while (t_gnl->line_chars_count > t_gnl->counter && *buffer != '\0')
	{
		t_gnl->line[t_gnl->counter++] = *buffer;
		buffer++;
	}
	if (*buffer == '\n' )
		buffer++;
	t_gnl->line[t_gnl->counter] = '\0';
	t_gnl->next_buffer = buffer;
	return ;
}

void	init_var(t_gnl *t_gnl)
{
	t_gnl->line = NULL;
	t_gnl->next_buffer = NULL;
	t_gnl->line_chars_count = 0;
	t_gnl->counter = 0;
	return ;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	t_gnl		t_gnl;

	init_var(&t_gnl);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(buffer, fd);
	if (!buffer)
		return (NULL);
	ft_get_line(buffer, &t_gnl);
	buffer = t_gnl.next_buffer;
	return (t_gnl.line);
}
