/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 05:17:10 by rkanmado          #+#    #+#             */
/*   Updated: 2022/07/28 06:04:20 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
