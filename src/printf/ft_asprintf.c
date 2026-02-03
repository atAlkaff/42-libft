/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 23:32:56 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/03 23:45:11 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <limits.h>

int	ft_asprintf(char **strp, const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_vasprintf(strp, format, args);
	va_end(args);
	return (len);
}

int	ft_vasprintf(char **strp, const char *format, va_list args)
{
	size_t	len;
	int		result;

	if (!strp)
		return (-1);
	len = get_total_len(format, args);
	if (len > INT_MAX)
	{
		*strp = NULL;
		return (-1);
	}
	*strp = malloc(len + 1);
	if (!*strp)
	{
		*strp = NULL;
		return (-1);
	}
	result = ft_vsprintf(*strp, format, args);
	if (result < 0)
	{
		free(*strp);
		return (-1);
	}
	return (result);
}
