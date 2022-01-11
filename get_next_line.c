/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:32:12 by hlucas            #+#    #+#             */
/*   Updated: 2022/01/11 16:53:57 by hlucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	

static char	*read_and_add(int fd, char *buffer, char *remaining)
{
	int		bytes_read;
	char	*char_temp;

	bytes_read = 1;
	while (bytes_read != '\0')
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!remaining)
			remaining = ft_strdup("");
		char_temp = remaining;
		remaining = ft_strjoin(char_temp, buffer);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (remaining);
}

static char	*update_next_line(char *line)
{
	size_t	count;
	char	*remaining;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	remaining = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*remaining == '\0')
	{
		free(remaining);
		remaining = NULL;
	}
	line[count + 1] = '\0';
	return (remaining);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*remaining;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = read_and_add(fd, buffer, remaining);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remaining = update_next_line(line);
	return (line);
}
