/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 20:31:40 by aalkaff           #+#    #+#             */
/*   Updated: 2025/08/23 20:45:22 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	src_len;
	size_t	copy_len;

	src_len = ft_strlen(src);
	if (n == 0)
		return (src_len);
	copy_len = src_len;
	if (copy_len > n - 1)
		copy_len = n - 1;
	ft_memcpy(dest, src, copy_len);
	dest[copy_len] = '\0';
	return (src_len);
}
