/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:16:46 by aalkaff           #+#    #+#             */
/*   Updated: 2025/10/29 22:19:41 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>	// write
#include <limits.h>	// INT_MIN

/**
 * @internal
 * @brief Stores the digits of @p n in @p digits.
 * @param digits The array of digits.
 * @param i The index of the array.
 * @param n The original number.
 * @returns The index of the leftmost digit.
 */
static size_t	get_digits(char *digits, size_t i, int n)
{
	while (n)
	{
		digits[i--] = n % 10 + '0';
		n /= 10;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	digits[22];
	char	negative;
	size_t	i;

	digits[21] = 0;
	i = 20;
	if (n == 0)
		digits[i--] = '0';
	negative = n < 0;
	if (n == INT_MIN)
	{
		digits[i--] = (unsigned)n % 10 + '0';
		n /= 10;
	}
	if (negative)
		n = -n;
	i = get_digits(digits, i, n);
	if (negative)
		digits[i--] = '-';
	write(fd, digits + i + 1, 20 - i);
}
