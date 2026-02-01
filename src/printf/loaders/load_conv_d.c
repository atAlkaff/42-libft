/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_conv_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:40:50 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/01 19:42:45 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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

static void	init_d_parts(t_dec_parts *p, const t_format *f, int d)
{
	p->sign_char = 0;
	p->value = d;
	if (d < 0)
	{
		p->sign_char = '-';
		p->value = (unsigned int)-d;
	}
	else if (f->flags & FMT_PLUS_SIGN_SHOW)
		p->sign_char = '+';
	else if (f->flags & FMT_PLUS_SIGN_SPACE)
		p->sign_char = ' ';
	p->num_len = count_digits_10(p->value);
	if (p->value == 0 && (f->flags & FMT_PRECISION_ON) && !f->precision)
		p->num_len = 0;
	if ((f->flags & FMT_PRECISION_ON) && p->num_len < f->precision)
		p->num_len = f->precision;
	p->pad_len = 0;
	if (f->width > p->num_len + (p->sign_char != 0))
		p->pad_len = f->width - (p->num_len + (p->sign_char != 0));
}

static void	d_left(char *buf, size_t n, t_dec_parts *p)
{
	size_t	offset;

	offset = 0;
	if (p->sign_char != 0)
	{
		if (n > 0)
			buf[0] = p->sign_char;
		offset = 1;
	}
	if (n > offset)
		safe_utoa(buf + offset, n - offset, p->value, p->num_len);
	offset += p->num_len;
	if (n > offset)
		ft_memset(buf + offset, ' ', min(p->pad_len, n - offset));
}

static void	d_right(char *buf, size_t n, t_dec_parts *p, const t_format *f)
{
	size_t	offset;

	if ((f->flags & FMT_ZERO_PAD) && !(f->flags & FMT_PRECISION_ON))
	{
		offset = (p->sign_char != 0);
		if (offset && n > 0)
			buf[0] = p->sign_char;
		if (n > offset)
			ft_memset(buf + offset, '0', min(p->pad_len, n - offset));
		offset += p->pad_len;
	}
	else
	{
		ft_memset(buf, ' ', min(p->pad_len, n));
		offset = p->pad_len;
		if (p->sign_char != 0 && n > offset)
			buf[offset++] = p->sign_char;
	}
	if (n > offset)
		safe_utoa(buf + offset, n - offset, p->value, p->num_len);
}

char	*load_conv_d(char *buf, size_t n, const t_format *f, int d)
{
	t_dec_parts	p;
	size_t		total;

	init_d_parts(&p, f, d);
	if (f->flags & FMT_LEFT_JUSTIFY)
		d_left(buf, n, &p);
	else
		d_right(buf, n, &p, f);
	total = p.num_len + p.pad_len + (p.sign_char != 0);
	if (total < n)
		return (buf + total);
	return (buf + n);
}
