/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 22:22:21 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/10/30 23:31:49 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*cbuf = NULL;
	static size_t	cpos = 0;

	if (!cbuf)
		cbuf = (char *)malloc(BUFFER_SIZE);
	// start reading from current pos in current buffer
	// dump buffer in cbuf every time
	// join together buffers until we get a complete line or EOF
	// return that string
	return (NULL);
}
