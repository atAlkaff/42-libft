/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:14:30 by aalkaff           #+#    #+#             */
/*   Updated: 2025/08/22 22:22:46 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>	// malloc
#include <stdint.h> // PTRDIFF_MAX

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_bytes;
	void	*ptr;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > PTRDIFF_MAX / size)
		return (NULL);
	total_bytes = nmemb * size;
	ptr = malloc(total_bytes);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_bytes);
	return (ptr);
}
