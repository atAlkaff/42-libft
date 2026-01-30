/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:40:47 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/30 22:33:42 by aalkaff          ###   ########.fr       */
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	src_len;
	size_t	copy_len;

	src_len = ft_strlen(src);
	if (dsize == 0)
		return (src_len);
	if (src_len >= dsize)
		copy_len = dsize - 1;
	else
		copy_len = src_len;
	ft_memcpy(dst, src, copy_len);
	dst[copy_len] = '\0';
	return (src_len);
}
