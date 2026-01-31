/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:01:58 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/31 20:04:38 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static ssize_t	find_newline_index(t_vector *vec)
{
	size_t	i;

	i = 0;
	while (i < vec->size)
	{
		if (vec->data[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*make_line(t_vector *vec, size_t *line_len)
{
	char	*line;
	size_t	i;
	ssize_t	newline_index;

	if (vec->size == 0)
		return (NULL);
	newline_index = find_newline_index(vec);
	if (newline_index != -1)
		*line_len = newline_index + 1;
	else
		*line_len = vec->size;
	line = malloc(*line_len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < *line_len)
	{
		line[i] = vec->data[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*make_stash(t_vector *vec, size_t line_len)
{
	char	*stash;
	size_t	i;

	if (vec->size <= line_len)
		return (NULL);
	stash = malloc((vec->size - line_len) + 1);
	if (!stash)
		return (NULL);
	i = 0;
	while (line_len + i < vec->size)
	{
		stash[i] = vec->data[line_len + i];
		i++;
	}
	stash[i] = '\0';
	return (stash);
}

static int	vec_read(t_vector *vec, int fd)
{
	ssize_t	bytes_read;

	if (!vec_ensure_capacity(vec, BUFFER_SIZE))
		return (GNL_READ_FAILED);
	bytes_read = read(fd, vec->data + vec->size, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(vec->data);
		return (GNL_READ_FAILED);
	}
	if (bytes_read == 0)
		return (GNL_REACHED_EOF);
	vec->size += bytes_read;
	vec->data[vec->size] = '\0';
	return (GNL_CONTINUE);
}

char	*get_next_line(int fd)
{
	static char	*stash[FD_MAX];
	t_vector	vec;
	char		*line;
	size_t		len;
	int			status;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!vec_init(&vec, &stash[fd]))
		return (NULL);
	free(stash[fd]);
	stash[fd] = NULL;
	while (find_newline_index(&vec) == -1)
	{
		status = vec_read(&vec, fd);
		if (status == GNL_READ_FAILED)
			return (NULL);
		if (status == GNL_REACHED_EOF)
			break ;
	}
	line = make_line(&vec, &len);
	if (line)
		stash[fd] = make_stash(&vec, len);
	free(vec.data);
	return (line);
}
