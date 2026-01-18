/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:40:47 by aalkaff           #+#    #+#             */
/*   Updated: 2025/10/28 20:46:54 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_byte;
	const unsigned char	*src_byte;
	size_t				i;

	dst_byte = (unsigned char *)dst;
	src_byte = (const unsigned char *)src;
	if (dst_byte == src_byte || n == 0)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst_byte[i] = src_byte[i];
		i++;
	}
	return (dst);
}
