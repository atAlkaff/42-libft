/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparisons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:48:06 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/01 18:49:36 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	imin(long a, long b)
{
	if (a < b)
		return (a);
	return (b);
}

long	imax(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}

unsigned long	min(unsigned long a, unsigned long b)
{
	if (a < b)
		return (a);
	return (b);
}

unsigned long	max(unsigned long a, unsigned long b)
{
	if (a > b)
		return (a);
	return (b);
}
