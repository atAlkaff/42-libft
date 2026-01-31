/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:31:55 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/31 18:59:28 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>	// malloc
#include <stdint.h>	// SIZE_MAX
#include <errno.h>	// ENOMEM

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;
	size_t	len;

	if (elsize != 0 && nelem > SIZE_MAX / elsize)
	{
		ft_seterrno(ENOMEM);
		return (NULL);
	}
	len = nelem * elsize;
	if (len == 0)
		len = 1;
	ptr = malloc(len);
	if (!ptr)
	{
		ft_seterrno(ENOMEM);
		return (NULL);
	}
	ft_memset(ptr, 0, len);
	return (ptr);
}
