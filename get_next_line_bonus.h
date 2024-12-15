/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:39:34 by juduchar          #+#    #+#             */
/*   Updated: 2024/12/13 17:39:38 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# if BUFFER_SIZE > 1000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_file
{
	int		fd;
	char	*remaining;
	char	buffer[BUFFER_SIZE + 1];
}				t_file;

t_file	*ft_get_or_create_file_struct(int fd, t_file **files);
void	ft_free_file(t_file **file);
char	*get_next_line(int fd);
char	*ft_strcopy(const char *src, size_t size);
char	*ft_strconcat(char *dst, const char *src,
			size_t dst_len, size_t src_len);
char	*ft_strchr(char *s, char c);
size_t	ft_strlen(const char *str);

#endif
