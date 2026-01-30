/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:56:32 by aalkaff           #+#    #+#             */
/*   Updated: 2025/11/14 15:35:28 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*dispatch_conversion(char *buf, t_format *f, va_list ap)
{
	if (f->specifier == 'c')
		return (load_conv_c(buf, f, va_arg(ap, int)));
	if (f->specifier == 's')
		return (load_conv_s(buf, f, va_arg(ap, char *)));
	if (f->specifier == 'p')
		return (load_conv_p(buf, f, va_arg(ap, void *)));
	if (f->specifier == 'd' || f->specifier == 'i')
		return (load_conv_d(buf, f, va_arg(ap, int)));
	if (f->specifier == 'u')
		return (load_conv_u(buf, f, va_arg(ap, unsigned int)));
	if (f->specifier == 'x')
		return (load_conv_x(buf, f, va_arg(ap, unsigned int)));
	if (f->specifier == 'X')
		return (load_conv_xx(buf, f, va_arg(ap, unsigned int)));
	if (f->specifier == '%')
		return (load_conv_c(buf, f, '%'));
	return (buf);
}

void	load_string(char *buf, const char *format, va_list args)
{
	const char	*p;
	t_format	f;

	p = format;
	while (*p)
	{
		if (*p == '%')
		{
			p++;
			p = parse_format(p, &f, args);
			if (f.specifier)
				buf = dispatch_conversion(buf, &f, args);
		}
		else
			*buf++ = *p++;
	}
	*buf = '\0';
}
