/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_conv_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:07:35 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/01 19:34:52 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdint.h>

static size_t	get_plen(uintptr_t p)
{
	return (count_digits_16(p) + 2);
}

static void	safe_xtoa(char *buf, size_t n, uintptr_t p, size_t len)
{
	size_t	i;
	char	*base;

	base = "0123456789abcdef";
	i = len;
	while (i > 0)
	{
		i--;
		if (i < n)
			buf[i] = base[p % 16];
		p /= 16;
	}
}

static char	*p_left(char *buf, size_t n, size_t width, uintptr_t p)
{
	size_t	len;
	size_t	to_write;

	len = get_plen(p);
	to_write = min(2, n);
	ft_memcpy(buf, "0x", to_write);
	if (n > 2)
		safe_xtoa(buf + 2, n - 2, p, len - 2);
	to_write = min(len, n);
	if (width > len && n > to_write)
	{
		ft_memset(buf + to_write, ' ', min(width - len, n - to_write));
		return (buf + to_write + min(width - len, n - to_write));
	}
	return (buf + to_write);
}

static char	*p_right(char *buf, size_t n, size_t width, uintptr_t p)
{
	size_t	len;
	size_t	pad;
	size_t	rem;

	len = get_plen(p);
	pad = 0;
	if (width > len)
		pad = min(width - len, n);
	ft_memset(buf, ' ', pad);
	if (n > pad)
	{
		rem = n - pad;
		ft_memcpy(buf + pad, "0x", min(2, rem));
		if (rem > 2)
			safe_xtoa(buf + pad + 2, rem - 2, p, len - 2);
		return (buf + pad + min(len, rem));
	}
	return (buf + pad);
}

char	*load_conv_p(char *buf, size_t n, const t_format *f, void *p)
{
	if (f->flags & FMT_LEFT_JUSTIFY)
		return (p_left(buf, n, f->width, (uintptr_t)p));
	return (p_right(buf, n, f->width, (uintptr_t)p));
}
