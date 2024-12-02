/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:39:46 by juduchar          #+#    #+#             */
/*   Updated: 2024/12/02 12:45:16 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 8

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	size_t	bytes_read;
	static char	*str;
	size_t	i;

	i = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (i < bytes_read && buffer[i] != '\n')
		i++;
	str = (char *) malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, buffer, i + 1);
	return (str);
}