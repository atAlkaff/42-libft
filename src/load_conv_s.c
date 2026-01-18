/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_conv_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:25:20 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/18 19:53:47 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*load_conv_s(char *buf, const t_format *f, const char *s)
{
	size_t	len;

	if (!s)
		s = "(null)";
	if (f->flags & FMT_PRECISION_ON)
		len = ft_strnlen(s, f->precision);
	else
		len = ft_strlen(s);
	if (f->width <= len)
	{
		ft_memcpy(buf, s, len);
		return (buf + len);
	}
	if (f->flags & FMT_LEFT_JUSTIFY)
	{
		ft_memcpy(buf, s, len);
		ft_memset(buf + len, ' ', f->width - len);
	}
	else
	{
		ft_memset(buf, ' ', f->width - len);
		ft_memcpy(buf + f->width - len, s, len);
	}
	return (buf + f->width);
}
