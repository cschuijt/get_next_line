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
	static char		*buffer = NULL;
	static size_t	pos = (size_t) BUFFER_SIZE;
	char			*line;

	if (!buffer)
		buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = NULL;
	while (!ends_in_newline(line))
	{
		if (pos >= BUFFER_SIZE || !buffer[pos])
			if (get_next_buffer(fd, buffer, &pos) <= 0)
				return (line);
		pos += add_to_str(&line, buffer[pos], length_until_newline(buffer));
		if (!line)
		{
			free(buffer);
			return (line);
		}
	}
	return (line);
}
