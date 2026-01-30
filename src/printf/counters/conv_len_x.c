/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_len_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:16:23 by aalkaff           #+#    #+#             */
/*   Updated: 2025/11/12 19:22:08 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	conv_len_x(const t_format *f, unsigned int x)
{
	size_t	len;

	if (x == 0 && (f->flags & FMT_PRECISION_ON) && f->precision == 0)
	{
		if (f->width > 0)
			return (f->width);
		return (0);
	}
	len = count_digits_16(x);
	if ((f->flags & FMT_PRECISION_ON) && len < f->precision)
		len = f->precision;
	if ((f->flags & FMT_ALT_FORM) && x != 0)
		len += 2;
	if (len < f->width)
		len = f->width;
	return (len);
}
