/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_conv_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:21:33 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/18 19:53:56 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	handle_right_align(char *buf, const t_format *f,
	unsigned int u, size_t ndigits)
{
	if ((f->flags & FMT_ZERO_PAD) && !(f->flags & FMT_PRECISION_ON))
		ft_memset(buf, '0', f->width - ndigits);
	else
		ft_memset(buf, ' ', f->width - ndigits);
	ft_utoa_stack(buf + f->width - ndigits, u, ndigits);
}

char	*load_conv_u(char *buf, const t_format *f, unsigned int u)
{
	size_t		ndigits;

	ndigits = count_digits_10(u);
	if (u == 0 && (f->flags & FMT_PRECISION_ON) && f->precision == 0)
		ndigits = 0;
	if ((f->flags & FMT_PRECISION_ON) && ndigits < f->precision)
		ndigits = f->precision;
	if (f->width <= ndigits)
	{
		ft_utoa_stack(buf, u, ndigits);
		return (buf + ndigits);
	}
	if (f->flags & FMT_LEFT_JUSTIFY)
	{
		ft_utoa_stack(buf, u, ndigits);
		ft_memset(buf + ndigits, ' ', f->width - ndigits);
	}
	else
		handle_right_align(buf, f, u, ndigits);
	return (buf + f->width);
}
