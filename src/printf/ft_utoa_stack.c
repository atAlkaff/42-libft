/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:36:41 by aalkaff           #+#    #+#             */
/*   Updated: 2025/11/12 20:15:03 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_xtoa_stack(char *buf, unsigned long n, size_t ndigits)
{
	size_t	i;

	i = ndigits;
	while (i > 0)
	{
		--i;
		buf[i] = "0123456789abcdef"[n & 15];
		n >>= 4;
	}
}

void	ft_xxtoa_stack(char *buf, unsigned long n, size_t ndigits)
{
	size_t	i;

	i = ndigits;
	while (i > 0)
	{
		--i;
		buf[i] = "0123456789ABCDEF"[n & 15];
		n >>= 4;
	}
}

void	ft_utoa_stack(char *buf, unsigned long n, size_t ndigits)
{
	size_t	i;

	i = ndigits;
	while (i > 0)
	{
		--i;
		buf[i] = n % 10 + '0';
		n /= 10;
	}
}
