/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_len_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:31:37 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/18 19:59:19 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	conv_len_d(const t_format *f, int d)
{
	size_t	len;

	if (d == 0 && (f->flags & FMT_PRECISION_ON) && f->precision == 0)
		len = 0;
	else
		len = count_digits_10i(d);
	if ((f->flags & FMT_PRECISION_ON) && len < f->precision)
		len = f->precision;
	if (d < 0)
		len += 1;
	else if ((f->flags & FMT_PLUS_SIGN_SHOW)
		|| (f->flags & FMT_PLUS_SIGN_SPACE))
		len += 1;
	if (len < f->width)
		len = f->width;
	return (len);
}
