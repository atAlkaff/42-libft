/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:24:35 by aalkaff           #+#    #+#             */
/*   Updated: 2025/10/29 21:28:33 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>	// malloc

char	*ft_strjoin(const char *prefix, const char *suffix)
{
	char	*result;
	size_t	prefix_len;
	size_t	suffix_len;

	if (!prefix || !suffix)
		return (NULL);
	prefix_len = ft_strlen(prefix);
	suffix_len = ft_strlen(suffix);
	result = malloc(prefix_len + suffix_len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, prefix, prefix_len);
	ft_memcpy(result + prefix_len, suffix, suffix_len);
	result[prefix_len + suffix_len] = '\0';
	return (result);
}
