/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:10:51 by aalkaff           #+#    #+#             */
/*   Updated: 2025/10/31 09:34:28 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>	// LONG_MIN, LONG_MAX

static long	load_digit_overflow_check(long number,
	unsigned char digit, char sign)
{
	if (sign == 1)
	{
		if (number > LONG_MAX / 10)
			return (LONG_MAX);
		if (number == LONG_MAX / 10 && digit > LONG_MAX % 10)
			return (LONG_MAX);
	}
	else
	{
		if (number < LONG_MIN / 10)
			return (LONG_MIN);
		if (number == LONG_MIN / 10 && digit > (unsigned long)LONG_MIN % 10)
			return (LONG_MIN);
	}
	return (10 * number + digit * sign);
}

int	ft_atoi(const char *nptr)
{
	long			result;
	char			sign;
	unsigned char	digit;

	while (*nptr == ' ' || (unsigned)(*nptr - '\t') < 5)
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
			sign = -1;
	}
	result = 0;
	while ((unsigned)(*nptr - '0') < 10)
	{
		digit = *nptr++ - '0';
		result = load_digit_overflow_check(result, digit, sign);
		if (result == LONG_MAX || result == LONG_MIN)
			break ;
	}
	return ((int)result);
}
