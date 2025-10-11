/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:47:31 by aalkaff           #+#    #+#             */
/*   Updated: 2025/10/11 21:08:34 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	copy_len;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (dlen >= dstsize)
		return (dstsize + slen);
	copy_len = dstsize - dlen - 1;
	if (copy_len > slen)
		copy_len = slen;
	ft_memcpy(dest + dlen, src, copy_len);
	dest[dlen + copy_len] = '\0';
	return (dlen + slen);
}
