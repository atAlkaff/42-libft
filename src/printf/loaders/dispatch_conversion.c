/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:56:32 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/01 19:38:21 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dispatch_conversion(char *buf, size_t n, t_format *f, va_list ap)
{
	if (n == 0)
		return (buf);
	if (f->specifier == 'c')
		return (load_conv_c(buf, n, f, va_arg(ap, int)));
	if (f->specifier == 's')
		return (load_conv_s(buf, n, f, va_arg(ap, char *)));
	if (f->specifier == 'p')
		return (load_conv_p(buf, n, f, va_arg(ap, void *)));
	if (f->specifier == 'd' || f->specifier == 'i')
		return (load_conv_d(buf, n, f, va_arg(ap, int)));
	if (f->specifier == 'u')
		return (load_conv_u(buf, n, f, va_arg(ap, unsigned int)));
	if ((f->specifier | 0x20) == 'x')
		return (load_conv_x(buf, n, f, va_arg(ap, unsigned int)));
	if (f->specifier == '%')
		return (load_conv_c(buf, n, f, '%'));
	return (buf);
}
