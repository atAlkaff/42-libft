/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:36:12 by aalkaff           #+#    #+#             */
/*   Updated: 2025/10/11 21:10:31 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	diff;

	while (*s1 && *s2 && n)
	{
		diff = (unsigned char)*s1 - (unsigned char)*s2;
		if (diff)
			return (diff);
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	diff = (unsigned char)*s1 - (unsigned char)*s2;
	return (diff);
}
