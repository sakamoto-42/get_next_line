/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakamoto-42 <sakamoto-42@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:52:48 by sakamoto-42       #+#    #+#             */
/*   Updated: 2024/12/06 17:45:18 by sakamoto-42      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd);

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;

	if (argc - 1 == 1)
	{
		fd = open(argv[1], O_RDONLY);
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
}
