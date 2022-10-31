/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 22:22:21 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/10/31 22:22:40 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*cbuf = NULL;
	static size_t	cpos = (size_t) BUFFER_SIZE;
	size_t			read_bytes;

	if (!cbuf)
		cbuf = malloc(BUFFER_SIZE);
	if (cpos == BUFFER_SIZE)
	{
		read_bytes = read(fd, cbuf, BUFFER_SIZE);
		cpos = 0;
	}
	return (NULL);
}
