/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:53:10 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/01 19:53:20 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <limits.h>

static char	*process_step(char *str, const char **fmt, va_list args, size_t rem)
{
	t_format	f;

	if (**fmt == '%')
	{
		(*fmt)++;
		*fmt = parse_format(*fmt, &f, args);
		if (f.specifier)
			return (dispatch_conversion(str, rem, &f, args));
	}
	else
	{
		if (rem > 0)
			*str++ = **fmt;
		(*fmt)++;
	}
	return (str);
}

int	ft_vsnprintf(char *str, size_t n, const char *format, va_list args)
{
	int		total;
	char	*start;
	size_t	rem;

	total = get_total_len(format, args);
	if (total > INT_MAX)
		return (-1);
	if (n == 0)
		return (total);
	start = str;
	while (*format)
	{
		rem = 0;
		if ((size_t)(str - start) < n - 1)
			rem = (n - 1) - (str - start);
		str = process_step(str, &format, args, rem);
	}
	*str = '\0';
	return (total);
}

int	ft_snprintf(char *str, size_t n, const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_vsnprintf(str, n, format, args);
	va_end(args);
	return (len);
}
