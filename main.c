/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 23:24:45 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/11/01 23:24:45 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> 

int	main(int argc, char **argv)
{
	int fd;
	char *str = "";

	if (argc < 2)
	{
		printf("No file specified!\n");
		return (1);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd < 0)
	{
		printf("File opening unsuccessful!\n");
		return (-2);
	}

	while (str)
	{
		str = get_next_line(fd);
		if (str)
		{
			printf("%s", str);
			free (str);
		}
		else
			break ;
	}
	close(fd);
	return (0);
}
