/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:14:40 by nhamad            #+#    #+#             */
/*   Updated: 2026/02/17 21:10:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_free(char *text, char *buffer)
{
	char	*tmp;

	tmp = gnl_strjoin(text, buffer);
	if (!tmp)
	{
		free(text);
		return (NULL);
	}
	free(text);
	return (tmp);
}

char	*read_file(int fd, char *line)
{
	char	*buf;
	int		br;

	if (!line)
	{
		line = ft_calloc(1, 1);
		if (!line)
			return (NULL);
	}
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(line), NULL);
	while (!gnl_strchr(line, '\n'))
	{
		br = read(fd, buf, BUFFER_SIZE);
		if (br == -1)
			return (free(buf), free(line), NULL);
		if (br == 0)
			break ;
		buf[br] = '\0';
		line = join_free(line, buf);
		if (!line)
			return (free(buf), NULL);
	}
	return (free(buf), line);
}

char	*gnl_getline(char *line)
{
	int		i;
	char	*str;

	if (!line || line[0] == '\0')
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		str[i] = '\n';
	return (str);
}

char	*clean_line(char *line)
{
	int		i;
	int		j;
	char	*rest;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	rest = ft_calloc(gnl_strlen(line) - i, sizeof(char));
	if (!rest)
		return (free(line), NULL);
	i++;
	j = 0;
	while (line[i])
		rest[j++] = line[i++];
	free(line);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line_out;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line_out = gnl_getline(stash);
	if (!line_out)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_line(stash);
	if (!stash)
	{
		len = gnl_strlen(line_out);
		if (len > 0 && line_out[len - 1] == '\n')
			return (free(line_out), NULL);
	}
	return (line_out);
}
