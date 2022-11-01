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

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *str;

	while (1)
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (!str)
			break ;
		free(str);
	}
	close(fd);
	return (0);
}
