/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:41:16 by juduchar          #+#    #+#             */
/*   Updated: 2024/12/02 12:44:37 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

int	main(int argc, char **argv)
{
	char	*file_name;
	int		fd;
	char	*str;

	if (argc - 1 == 1)
	{
		file_name = argv[1];
		fd = open(file_name, O_RDONLY);
		str = get_next_line(fd);
		ft_putstr(str);
		write(1,"\n", 1);
		str = get_next_line(fd);
		ft_putstr(str);
		close(fd);
	}
	else
		return (1);
}