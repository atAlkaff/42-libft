/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_conv_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:25:20 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/01 19:24:19 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	get_slen(const t_format *f, const char *s)
{
	if (f->flags & FMT_PRECISION_ON)
		return (ft_strnlen(s, f->precision));
	return (ft_strlen(s));
}

static char	*load_s_left(char *buf, size_t n, const t_format *f, const char *s)
{
	size_t	len;
	size_t	to_write;
	size_t	pad_len;

	len = get_slen(f, s);
	to_write = min(len, n);
	ft_memcpy(buf, s, to_write);
	if (n > to_write)
	{
		pad_len = min(f->width - len, n - to_write);
		ft_memset(buf + to_write, ' ', pad_len);
		return (buf + to_write + pad_len);
	}
	return (buf + to_write);
}

static char	*load_s_right(char *buf, size_t n, const t_format *f, const char *s)
{
	size_t	len;
	size_t	pad_len;
	size_t	to_write;

	len = get_slen(f, s);
	pad_len = min(f->width - len, n);
	ft_memset(buf, ' ', pad_len);
	if (n > pad_len)
	{
		to_write = min(len, n - pad_len);
		ft_memcpy(buf + pad_len, s, to_write);
		return (buf + pad_len + to_write);
	}
	return (buf + pad_len);
}

char	*load_conv_s(char *buf, size_t n, const t_format *f, const char *s)
{
	size_t	len;

	if (!s)
		s = "(null)";
	len = get_slen(f, s);
	if (f->width <= len)
	{
		len = min(len, n);
		ft_memcpy(buf, s, len);
		return (buf + len);
	}
	if (f->flags & FMT_LEFT_JUSTIFY)
		return (load_s_left(buf, n, f, s));
	return (load_s_right(buf, n, f, s));
}
