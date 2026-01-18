/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_conv_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:07:35 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/18 19:53:40 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdint.h>

char	*load_conv_p(char *buf, const t_format *f, void *p)
{
	size_t		ndigits;
	uintptr_t	p_int;

	p_int = (uintptr_t)p;
	ndigits = count_digits_16(p_int);
	if (f->width <= ndigits + 2)
	{
		ft_memcpy(buf, "0x", 2);
		ft_xtoa_stack(buf + 2, p_int, ndigits);
		return (buf + ndigits + 2);
	}
	if (f->flags & FMT_LEFT_JUSTIFY)
	{
		ft_memcpy(buf, "0x", 2);
		ft_xtoa_stack(buf + 2, p_int, ndigits);
		ft_memset(buf + ndigits + 2, ' ', f->width - ndigits - 2);
	}
	else
	{
		ft_memset(buf, ' ', f->width - ndigits - 2);
		ft_memcpy(buf + f->width - ndigits - 2, "0x", 2);
		ft_xtoa_stack(buf + f->width - ndigits, p_int, ndigits);
	}
	return (buf + f->width);
}
