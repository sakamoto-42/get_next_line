/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakamoto-42 <sakamoto-42@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:56:40 by sakamoto-42       #+#    #+#             */
/*   Updated: 2024/12/06 17:52:59 by sakamoto-42      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#if BUFFER_SIZE > 1000000
# undef BUFFER_SIZE
# define BUFFER_SIZE 1000000
#endif

#include <unistd.h>
#include <stdlib.h>

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcopy(const char *src, size_t size)
{
	char	*dst;
	size_t	i;

	dst = (char *) malloc((size + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strconcat(char *dst, const char *src)
{
	size_t	dst_len;
	size_t	src_len;
	char	*str;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	str = (char *) malloc((dst_len + src_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (dst)
	{
		while (i < dst_len)
		{
			str[i] = dst[i];
			i++;
		}
		free(dst);
	}
	j = 0;
	while (j < src_len)
	{
		str[i] = src[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_extract_line(char **remaining)
{
	char	*pos;
	char	*temp;
	char	*line;

	if (!*remaining || !**remaining)
		return (NULL);
	pos = ft_strchr(*remaining, '\n');
	if (!pos)
		return (NULL);
	line = ft_strcopy(*remaining, pos - *remaining + 1);
	if (!line)
		return (NULL);
	temp = ft_strcopy(pos + 1, ft_strlen(pos + 1));
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	free(*remaining);
	*remaining = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	line = ft_extract_line(&remaining);
	if (line)
		return (line);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		remaining = ft_strconcat(remaining, buffer);
		if (!remaining)
			return (NULL);
		line = ft_extract_line(&remaining);
		if (line)
			return (line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (NULL);
	if (remaining && *remaining)
	{
		line = ft_strcopy(remaining, ft_strlen(remaining));
		free(remaining);
		remaining = NULL;
		return (line);
	}
	free(remaining);
	remaining = NULL;
	return (NULL);
}
