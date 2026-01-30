/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:14:32 by aalkaff           #+#    #+#             */
/*   Updated: 2025/10/29 21:22:14 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>	// malloc

char	*ft_strtrim(const char *s1, const char *set)
{
	char			*substr;
	size_t			substr_len;
	unsigned char	isset[256];

	if (!s1 || !set)
		return (NULL);
	ft_bzero(isset, sizeof(isset));
	while (*set)
		isset[(unsigned char)(*set++)] = 1;
	while (isset[(unsigned char)(*s1)])
		s1++;
	substr_len = ft_strlen(s1);
	while (substr_len > 0 && isset[(unsigned char) s1[substr_len - 1]])
		substr_len--;
	substr = malloc(substr_len + 1);
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s1, substr_len);
	substr[substr_len] = '\0';
	return (substr);
}
