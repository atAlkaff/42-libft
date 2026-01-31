/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:40:21 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/31 20:00:20 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

static void	*ft_malloc_errno(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_seterrno(ENOMEM);
		return (NULL);
	}
	return (ptr);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	limit;

	if (!ptr)
		return (ft_malloc_errno(new_size));
	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = ft_malloc_errno(new_size);
	if (!new_ptr)
		return (NULL);
	limit = old_size;
	if (new_size < old_size)
		limit = new_size;
	ft_memcpy(new_ptr, ptr, limit);
	free(ptr);
	return (new_ptr);
}
