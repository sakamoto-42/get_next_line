/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakamoto-42 <sakamoto-42@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:56:40 by sakamoto-42       #+#    #+#             */
/*   Updated: 2024/12/06 17:17:17 by sakamoto-42      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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
	int		i;
	int		j;

	dst_len = 0;
	if (dst)
		dst_len = strlen(dst);
	src_len = 0;
	if (src)
		src_len = strlen(src);
	str = (char *) malloc((dst_len + src_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (dst)
	{
		while (dst[i])
		{
			str[i] = dst[i];
			i++;
		}
		free(dst);
	}
	j = 0;
	while (src[j])
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
	size_t	line_len;

	if (!(*remaining))
		return (NULL);
	pos = strchr(*remaining, '\n');
	if (!pos)
		return (NULL);
	line_len = pos - *remaining + 1;
	line = ft_strcopy(*remaining, line_len);
	if (!line)
		return (NULL);
	temp = ft_strcopy(pos + 1, strlen(pos + 1));
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

	remaining = NULL;
	line = ft_extract_line(&remaining);
	if (line)
		return (line);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		if (remaining && *remaining)
		{
			line = ft_strcopy(remaining, strlen(remaining));
			free(remaining);
			remaining = NULL;
			return (line);
		}
		free(remaining);
		remaining = NULL;
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	remaining = ft_strconcat(remaining, buffer);
	if (!remaining)
		return (NULL);	
	return (ft_extract_line(&remaining));
}
