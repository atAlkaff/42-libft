/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:29:20 by aalkaff           #+#    #+#             */
/*   Updated: 2025/09/29 22:31:18 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	nbytes;

	nbytes = ft_strlen(s) + 1;
	result = malloc(nbytes);
	if (!result)
		return (NULL);
	return (ft_memcpy(result, s, nbytes));
}
