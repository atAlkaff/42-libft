/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:52:34 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/01 18:09:50 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_vprintf(format, args);
	va_end(args);
	return (len);
}

int	ft_vprintf(const char *format, va_list args)
{
	return (ft_vdprintf(STDOUT_FILENO, format, args));
}
