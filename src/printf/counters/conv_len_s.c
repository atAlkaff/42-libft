/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_len_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:52:30 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/18 19:59:25 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	conv_len_s(const t_format *f, const char *s)
{
	size_t	len;

	if (!s)
		s = "(null)";
	if (f->flags & FMT_PRECISION_ON)
		len = ft_strnlen(s, f->precision);
	else
		len = ft_strlen(s);
	if (len < f->width)
		len = f->width;
	return (len);
}
