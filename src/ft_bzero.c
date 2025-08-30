/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:49:30 by aalkaff           #+#    #+#             */
/*   Updated: 2025/08/31 00:49:15 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h> // uintptr_t

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	*wptr;

	ptr = s;
	while ((uintptr_t)ptr & (sizeof(size_t) - 1) && n)
	{
		*ptr++ = 0;
		n--;
	}
	wptr = ptr;
	while (n >= sizeof(size_t))
	{
		*wptr++ = 0;
		n -= sizeof(size_t);
	}
	ptr = wptr;
	while (n--)
		*ptr++ = 0;
}
