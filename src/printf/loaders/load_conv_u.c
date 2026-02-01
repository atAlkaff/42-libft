/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_conv_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:21:33 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/01 19:31:30 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	get_ulen(const t_format *f, unsigned int u)
{
	size_t	len;

	len = count_digits_10(u);
	if (u == 0 && (f->flags & FMT_PRECISION_ON) && f->precision == 0)
		len = 0;
	if ((f->flags & FMT_PRECISION_ON) && len < f->precision)
		len = f->precision;
	return (len);
}

static void	safe_utoa(char *buf, size_t n, unsigned int u, size_t len)
{
	size_t	i;

	i = len;
	while (i > 0)
	{
		i--;
		if (i < n)
			buf[i] = (u % 10) + '0';
		u /= 10;
	}
}

static char	*u_left(char *buf, size_t n, const t_format *f, unsigned int u)
{
	size_t	len;
	size_t	to_write;
	size_t	pad;

	len = get_ulen(f, u);
	to_write = min(len, n);
	safe_utoa(buf, n, u, len);
	if (f->width > len && n > to_write)
	{
		pad = min(f->width - len, n - to_write);
		ft_memset(buf + to_write, ' ', pad);
		return (buf + to_write + pad);
	}
	return (buf + to_write);
}

static char	*u_right(char *buf, size_t n, const t_format *f, unsigned int u)
{
	size_t	len;
	size_t	pad;
	char	c;

	len = get_ulen(f, u);
	if (f->width <= len)
	{
		safe_utoa(buf, n, u, len);
		return (buf + min(len, n));
	}
	pad = min(f->width - len, n);
	c = ' ';
	if ((f->flags & FMT_ZERO_PAD) && !(f->flags & FMT_PRECISION_ON))
		c = '0';
	ft_memset(buf, c, pad);
	if (n > pad)
	{
		safe_utoa(buf + pad, n - pad, u, len);
		return (buf + pad + min(len, n - pad));
	}
	return (buf + pad);
}

/* 5. Main Dispatcher */
char	*load_conv_u(char *buf, size_t n, const t_format *f, unsigned int u)
{
	if (f->flags & FMT_LEFT_JUSTIFY)
		return (u_left(buf, n, f, u));
	return (u_right(buf, n, f, u));
}
