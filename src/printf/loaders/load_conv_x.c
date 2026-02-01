/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_conv_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:38:46 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/01 19:40:38 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	safe_xtoa(char *buf, size_t n, unsigned int u, const t_format *f)
{
	size_t	i;
	size_t	len;
	char	*base;

	len = count_digits_16(u);
	if (u == 0 && (f->flags & FMT_PRECISION_ON) && f->precision == 0)
		len = 0;
	else if ((f->flags & FMT_PRECISION_ON) && f->precision > len)
		len = f->precision;
	if (f->specifier == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = len;
	while (i > 0)
	{
		i--;
		if (i < n)
			buf[i] = base[u % 16];
		u /= 16;
	}
}

static void	init_hex_parts(t_hex_parts *p, const t_format *f, unsigned int u)
{
	size_t	total_len;

	p->value = u;
	p->prefix_len = 0;
	if ((f->flags & FMT_ALT_FORM) && u != 0)
		p->prefix_len = 2;
	p->num_len = count_digits_16(u);
	if (u == 0 && (f->flags & FMT_PRECISION_ON) && f->precision == 0)
		p->num_len = 0;
	if ((f->flags & FMT_PRECISION_ON) && f->precision > p->num_len)
		p->num_len = f->precision;
	total_len = p->num_len + p->prefix_len;
	p->pad_len = 0;
	if (f->width > total_len)
		p->pad_len = f->width - total_len;
}

static void	x_left(char *buf, size_t n, t_hex_parts *p, const t_format *f)
{
	size_t	w;
	char	*prefix;

	if (f->specifier == 'X')
		prefix = "0X";
	else
		prefix = "0x";
	w = min(p->prefix_len, n);
	ft_memcpy(buf, prefix, w);
	if (n > p->prefix_len)
		safe_xtoa(buf + p->prefix_len, n - p->prefix_len, p->value, f);
	w = p->prefix_len + p->num_len;
	if (n > w)
		ft_memset(buf + w, ' ', min(p->pad_len, n - w));
}

static void	x_right(char *buf, size_t n, t_hex_parts *p, const t_format *f)
{
	size_t	offset;
	char	*prefix;

	if (f->specifier == 'X')
		prefix = "0X";
	else
		prefix = "0x";
	if ((f->flags & FMT_ZERO_PAD) && !(f->flags & FMT_PRECISION_ON))
	{
		ft_memcpy(buf, prefix, min(p->prefix_len, n));
		if (n > p->prefix_len)
			ft_memset(buf + p->prefix_len, '0',
				min(p->pad_len, n - p->prefix_len));
		offset = p->prefix_len + p->pad_len;
	}
	else
	{
		ft_memset(buf, ' ', min(p->pad_len, n));
		if (n > p->pad_len)
			ft_memcpy(buf + p->pad_len, prefix,
				min(p->prefix_len, n - p->pad_len));
		offset = p->pad_len + p->prefix_len;
	}
	if (n > offset)
		safe_xtoa(buf + offset, n - offset, p->value, f);
}

char	*load_conv_x(char *buf, size_t n, const t_format *f, unsigned int u)
{
	t_hex_parts	p;
	size_t		total;

	init_hex_parts(&p, f, u);
	total = p.num_len + p.prefix_len + p.pad_len;
	if (f->flags & FMT_LEFT_JUSTIFY)
		x_left(buf, n, &p, f);
	else
		x_right(buf, n, &p, f);
	if (total < n)
		return (buf + total);
	return (buf + min(total, n));
}
