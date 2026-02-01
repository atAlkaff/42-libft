/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:52:29 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/01 19:56:51 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <limits.h>

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_vsprintf(str, format, args);
	va_end(args);
	return (len);
}

int	ft_vsprintf(char *str, const char *format, va_list args)
{
	return (ft_vsnprintf(str, INT_MAX, format, args));
}
