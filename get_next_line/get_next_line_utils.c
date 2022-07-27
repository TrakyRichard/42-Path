/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 05:17:10 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/27 10:20:50 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoins(char *chars_remaining, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!chars_remaining)
	{
		chars_remaining = (char *)malloc(1 * sizeof(char));
		chars_remaining[0] = '\0';
	}
	if (!chars_remaining || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(chars_remaining) + ft_strlen(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (chars_remaining)
		while (chars_remaining[++i] != '\0')
			str[i] = chars_remaining[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(chars_remaining) + ft_strlen(buffer)] = '\0';
	free(chars_remaining);
	return (str);
}

char	*ft_strcat(char *s1, char *s2)
{
	int		counter;
	int		source_len;
	char	*result;
	int		result_len;

	result_len = (ft_strlen(s1) +ft_strlen(s2));
	result = s1;
	counter = 0;
	source_len = ft_strlen(s1);
	while (s2[counter] != '\0' && source_len + counter < result_len)
	{
		result[source_len + counter] = s2[counter];
		counter++;
	}
	result[source_len + counter] = '\0';
	return (result);
}

char	*ft_strcpy(char *dst, char *src)
{
	int		counter;

	counter = 0;
	while (src[counter] != '\0')
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		len;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1 = "";
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	result = malloc(len * sizeof(char));
	if (result == NULL)
		return (NULL);
	result = ft_strcpy(result, s1);
	result = ft_strcat(result, s2);
	return (result);
}

char *ft_calloc(size_t count, size_t size)
{
	char *str;
	size_t counter;

	counter = count * size;
	str = malloc(count * size);
	if (str == NULL)
		return (NULL);

	while (counter--)
	{
		str[counter] = '\0';
	}
	return str;
}

int ft_has_new_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		return (i);
		i++;
	}
	return (-1);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
