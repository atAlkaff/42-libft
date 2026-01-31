/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:03:46 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/31 20:04:26 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

int	vec_init(t_vector *vec, char **stash)
{
	size_t	i;

	vec->size = 0;
	if (*stash)
		while ((*stash)[vec->size])
			vec->size++;
	vec->capacity = next_power_of_two(vec->size + BUFFER_SIZE);
	if (vec->capacity < 64)
		vec->capacity = 64;
	vec->data = malloc(vec->capacity);
	if (vec->data && *stash)
	{
		i = -1;
		while (++i < vec->size)
			vec->data[i] = (*stash)[i];
		vec->data[vec->size] = '\0';
	}
	if (*stash)
		free(*stash);
	*stash = NULL;
	return (vec->data != NULL);
}

int	vec_ensure_capacity(t_vector *vec, size_t extra_bytes)
{
	size_t	needed;
	size_t	new_cap;
	void	*temp;

	needed = vec->size + extra_bytes;
	if (needed >= vec->capacity)
	{
		new_cap = next_power_of_two(needed);
		if (new_cap < vec->capacity * 2)
			new_cap = vec->capacity * 2;
		temp = ft_realloc(vec->data, vec->capacity, new_cap);
		if (!temp)
		{
			free(vec->data);
			vec->data = NULL;
			return (0);
		}
		vec->data = temp;
		vec->capacity = new_cap;
	}
	return (1);
}
