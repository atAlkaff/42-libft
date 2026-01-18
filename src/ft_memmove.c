/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:42:58 by aalkaff           #+#    #+#             */
/*   Updated: 2025/10/28 20:49:00 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_byte;
	const unsigned char	*src_byte;
	size_t				i;

	dst_byte = (unsigned char *)dst;
	src_byte = (const unsigned char *)src;
	if (dst_byte == src_byte || n == 0)
		return (dst);
	if (dst_byte < src_byte || dst_byte >= src_byte + n)
	{
		i = 0;
		while (i < n)
		{
			dst_byte[i] = src_byte[i];
			i++;
		}
		return (dst);
	}
	i = n;
	while (i > 0)
	{
		i--;
		dst_byte[i] = src_byte[i];
	}
	return (dst);
}
