/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:21:02 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/31 18:53:37 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"
#include "libft.h"

static void	extract_sign(t_atoi_parts *atoi_struct)
{
	atoi_struct->sign = 1;
	if (*atoi_struct->nptr == '-' || *atoi_struct->nptr == '+')
	{
		if (*atoi_struct->nptr++ == '-')
			atoi_struct->sign = -1;
	}
}

static void	extract_base(t_atoi_parts *atoi_struct, unsigned int base)
{
	if (base == 0)
	{
		if (atoi_struct->nptr[0] == '0')
		{
			if ((atoi_struct->nptr[1] | 0x20) == 'x')
				base = 16;
			else
			{
				base = 8;
				atoi_struct->nptr++;
			}
		}
		else
			base = 10;
	}
	if (base == 16
		&& atoi_struct->nptr[0] == '0'
		&& (atoi_struct->nptr[1] | 0x20) == 'x'
		&& (unsigned)get_digit_value(atoi_struct->nptr[2]) < 16)
		atoi_struct->nptr += 2;
	atoi_struct->base = base;
}

int	get_digit_value(char c)
{
	if ((unsigned)(c - '0') < 10)
		return (c - '0');
	if ((unsigned)((c | 0x20) - 'a') < 26)
		return ((c | 0x20) - 'a');
	return (-1);
}

void	initialize_atoi_struct(t_atoi_parts *atoi_struct,
	const char *nptr, unsigned int base)
{
	while (*nptr == ' ' || (unsigned)(*nptr - '\t') < 5)
		nptr++;
	atoi_struct->nptr = nptr;
	extract_sign(atoi_struct);
	extract_base(atoi_struct, base);
	atoi_struct->result = 0;
}
