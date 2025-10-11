/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:26:37 by aalkaff           #+#    #+#             */
/*   Updated: 2025/09/29 22:51:45 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h> // uintptr_t

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;
	size_t	*wptr;
	size_t	mask;

	if (n == 0)
		return (s);
	ptr = s;
	while ((uintptr_t)ptr & (sizeof(size_t) - 1) && n)
	{
		*ptr++ = (unsigned char) c;
		n--;
	}
	wptr = (size_t *) ptr;
	mask = (unsigned char) c;
	mask |= mask << 8;
	mask |= mask << 16;
	mask |= mask << 32;
	while (n >= sizeof(size_t))
	{
		*wptr++ = mask;
		n -= sizeof(size_t);
	}
	ptr = (char *) wptr;
	while (n--)
		*ptr++ = (unsigned char) c;
	return (s);
}
