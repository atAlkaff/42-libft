/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_total_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:25:32 by aalkaff           #+#    #+#             */
/*   Updated: 2025/11/14 14:51:28 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	dispatch_length(t_format *f, va_list ap)
{
	if (f->specifier == 'c')
	{
		va_arg(ap, int);
		return (conv_len_c(f));
	}
	if (f->specifier == 's')
		return (conv_len_s(f, va_arg(ap, char *)));
	if (f->specifier == 'p')
		return (conv_len_p(f, va_arg(ap, void *)));
	if (f->specifier == 'd' || f->specifier == 'i')
		return (conv_len_d(f, va_arg(ap, int)));
	if (f->specifier == 'u')
		return (conv_len_u(f, va_arg(ap, unsigned int)));
	if (f->specifier == 'x' || f->specifier == 'X')
		return (conv_len_x(f, va_arg(ap, unsigned int)));
	if (f->specifier == '%')
		return (conv_len_c(f));
	return (0);
}

size_t	get_total_len(const char *format, va_list args)
{
	const char	*p;
	size_t		total_len;
	t_format	f;
	va_list		ap_copy;

	p = format;
	total_len = 0;
	va_copy(ap_copy, args);
	while (*p)
	{
		if (*p == '%')
		{
			p++;
			p = parse_format(p, &f, ap_copy);
			if (f.specifier)
				total_len += dispatch_length(&f, ap_copy);
		}
		else
		{
			total_len++;
			p++;
		}
	}
	va_end(ap_copy);
	return (total_len);
}
