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

void	haha(void)
{
	system("leaks a.out");
}

int	main(int argc, char **argv)
{
	int fd;
	char *str = "";
	int n = 1;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;

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
			printf("%d: [%s]", n, str);
			n++;
			free (str);
		}
		else
		{
			printf("Null encountered, wrote %d lines\n", n - 1);
			break ;
		}
	}
	close(fd);
	atexit(haha);
	return (0);
}
