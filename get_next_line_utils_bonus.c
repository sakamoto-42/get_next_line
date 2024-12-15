/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:40:00 by juduchar          #+#    #+#             */
/*   Updated: 2024/12/13 17:38:59 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
