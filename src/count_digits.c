/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:26:16 by aalkaff           #+#    #+#             */
/*   Updated: 2025/11/09 20:38:27 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_digits_10(unsigned long n)
{
	size_t	ndigits;

	if (n == 0)
		return (1);
	ndigits = 0;
	while (n)
	{
		n /= 10;
		ndigits++;
	}
	return (ndigits);
}

size_t	count_digits_10i(long n)
{
	size_t	ndigits;

	if (n == 0)
		return (1);
	ndigits = 0;
	while (n)
	{
		n /= 10;
		ndigits++;
	}
	return (ndigits);
}

size_t	count_digits_16(unsigned long n)
{
	size_t	ndigits;

	if (n == 0)
		return (1);
	ndigits = 0;
	while (n)
	{
		n >>= 4;
		ndigits++;
	}
	return (ndigits);
}
