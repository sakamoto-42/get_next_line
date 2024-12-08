/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:56:40 by sakamoto-42       #+#    #+#             */
/*   Updated: 2024/12/07 19:53:34 by sakamoto-42      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strconcat(char *dst, const char *src,
	size_t dst_len, size_t src_len)
{
	char	*str;
	size_t	i;
	size_t	j;

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
		str[i++] = src[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_extract_line(char **remaining)
{
	char	*nl_pos;
	char	*temp;
	char	*line;

	if (!*remaining || !**remaining)
		return (NULL);
	nl_pos = ft_strchr(*remaining, '\n');
	if (!nl_pos)
		return (NULL);
	line = ft_strcopy(*remaining, nl_pos - *remaining + 1);
	if (!line)
		return (NULL);
	temp = ft_strcopy(nl_pos + 1, ft_strlen(nl_pos + 1));
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
	static char	*remaining[1024];
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	line = ft_extract_line(&remaining[fd]);
	if (line)
		return (line);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		remaining[fd] = ft_strconcat(remaining[fd], buffer,
				ft_strlen(remaining[fd]), ft_strlen(buffer));
		if (!remaining[fd])
			return (NULL);
		line = ft_extract_line(&remaining[fd]);
		if (line)
			return (line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0 || (!remaining[fd] || !*remaining[fd]))
		return (free(remaining[fd]), remaining[fd] = NULL, NULL);
	line = ft_strcopy(remaining[fd], ft_strlen(remaining[fd]));
	return (free(remaining[fd]), remaining[fd] = NULL, line);
}
