/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:10:51 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/31 20:54:14 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>	// LONG_MIN, LONG_MAX
#include <errno.h>	// EINVAL
#include "ft_atoi.h"

static long	load_digit_overflow_check(t_atoi_parts *atoi_struct, int digit)
{
	if (atoi_struct->sign == 1)
	{
		if ((atoi_struct->result > LONG_MAX / atoi_struct->base)
			|| (atoi_struct->result == LONG_MAX / atoi_struct->base
				&& digit > LONG_MAX % atoi_struct->base))
		{
			ft_seterrno(ERANGE);
			return (LONG_MAX);
		}
	}
	else
	{
		if ((atoi_struct->result < LONG_MIN / atoi_struct->base)
			|| (atoi_struct->result == LONG_MIN / atoi_struct->base
				&& digit > -(LONG_MIN % atoi_struct->base)))
		{
			ft_seterrno(ERANGE);
			return (LONG_MIN);
		}
	}
	return (atoi_struct->base * atoi_struct->result
		+ digit * atoi_struct->sign);
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	t_atoi_parts	atoi_struct;
	int				digit;

	if (base && ((unsigned)base - 2) > 34)
	{
		ft_seterrno(EINVAL);
		return (0);
	}
	initialize_atoi_struct(&atoi_struct, nptr, base);
	digit = get_digit_value(*atoi_struct.nptr++);
	if ((unsigned)digit >= atoi_struct.base)
	{
		if (endptr)
			*endptr = (char *) nptr;
		return (0);
	}
	while ((unsigned)digit < atoi_struct.base)
	{
		if (atoi_struct.result != LONG_MAX && atoi_struct.result != LONG_MIN)
			atoi_struct.result = load_digit_overflow_check(&atoi_struct, digit);
		digit = get_digit_value(*atoi_struct.nptr++);
	}
	if (endptr)
		*endptr = (char *) atoi_struct.nptr - 1;
	return (atoi_struct.result);
}

int	ft_atoi(const char *nptr)
{
	return ((int)ft_strtol(nptr, (char **) NULL, 10));
}
