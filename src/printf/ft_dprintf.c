/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:02:08 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/01 18:07:36 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_vdprintf(fd, format, args);
	va_end(args);
	return (len);
}

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	size_t	len;
	int		bytes_written;
	char	*buf;

	len = get_total_len(format, args);
	if (len > INT_MAX)
	{
		va_end(args);
		return (-1);
	}
	buf = malloc(len + 1);
	if (!buf)
	{
		va_end(args);
		return (-1);
	}
	ft_vsprintf(buf, format, args);
	bytes_written = write(fd, buf, len);
	free(buf);
	return (bytes_written);
}
