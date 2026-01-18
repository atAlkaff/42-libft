/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_len_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:28:37 by aalkaff           #+#    #+#             */
/*   Updated: 2025/11/12 19:31:03 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	conv_len_u(const t_format *f, unsigned int u)
{
	size_t	len;

	if (u == 0 && (f->flags & FMT_PRECISION_ON) && f->precision == 0)
	{
		if (f->width > 0)
			return (f->width);
		return (0);
	}
	len = count_digits_10(u);
	if ((f->flags & FMT_PRECISION_ON) && len < f->precision)
		len = f->precision;
	if (len < f->width)
		len = f->width;
	return (len);
}
