/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:31:54 by aalkaff           #+#    #+#             */
/*   Updated: 2025/09/29 22:41:12 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_byte;
	const unsigned char	*s2_byte;
	int					diff;

	s1_byte = s1;
	s2_byte = s2;
	while (n)
	{
		diff = *s1_byte - *s2_byte;
		if (diff)
			return (diff);
		s1_byte++;
		s2_byte++;
		n--;
	}
	return (0);
}
