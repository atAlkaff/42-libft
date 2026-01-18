/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_conv_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:40:50 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/18 19:53:22 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	get_sign_char(int d, const t_format *f, unsigned int *n)
{
	char	sign_char;

	sign_char = 0;
	if (d < 0)
	{
		sign_char = '-';
		*n = (unsigned int)-d;
	}
	else
	{
		*n = d;
		if (f->flags & FMT_PLUS_SIGN_SHOW)
			sign_char = '+';
		else if (f->flags & FMT_PLUS_SIGN_SPACE)
			sign_char = ' ';
	}
	return (sign_char);
}

static size_t	get_num_len(const t_format *f, unsigned int n)
{
	size_t	num_len;

	if (n == 0 && (f->flags & FMT_PRECISION_ON) && f->precision == 0)
		num_len = 0;
	else
		num_len = count_digits_10(n);
	if ((f->flags & FMT_PRECISION_ON) && num_len < f->precision)
		num_len = f->precision;
	return (num_len);
}

static void	write_d_left(char *buf, t_dec_parts *p)
{
	size_t	sign_offset;

	sign_offset = 0;
	if (p->sign_char != 0)
	{
		buf[0] = p->sign_char;
		sign_offset = 1;
	}
	ft_utoa_stack(buf + sign_offset, p->value, p->num_len);
	ft_memset(buf + sign_offset + p->num_len, ' ', p->pad_len);
}

static void	write_d_right(char *buf, t_dec_parts *p, const t_format *f)
{
	size_t	sign_offset;

	sign_offset = 0;
	if ((f->flags & FMT_ZERO_PAD) && !(f->flags & FMT_PRECISION_ON))
	{
		if (p->sign_char != 0)
		{
			buf[0] = p->sign_char;
			sign_offset = 1;
		}
		ft_memset(buf + sign_offset, '0', p->pad_len);
		ft_utoa_stack(buf + sign_offset + p->pad_len, p->value, p->num_len);
	}
	else
	{
		ft_memset(buf, ' ', p->pad_len);
		if (p->sign_char != 0)
		{
			buf[p->pad_len] = p->sign_char;
			sign_offset = 1;
		}
		ft_utoa_stack(buf + p->pad_len + sign_offset, p->value, p->num_len);
	}
}

char	*load_conv_d(char *buf, const t_format *f, int d)
{
	t_dec_parts	parts;
	size_t		total_len;

	parts.sign_char = get_sign_char(d, f, &parts.value);
	parts.num_len = get_num_len(f, parts.value);
	total_len = parts.num_len + (parts.sign_char != 0);
	if (f->width <= total_len)
	{
		if (parts.sign_char != 0)
			buf[0] = parts.sign_char;
		ft_utoa_stack(buf + (parts.sign_char != 0), parts.value, parts.num_len);
		return (buf + total_len);
	}
	parts.pad_len = f->width - total_len;
	if (f->flags & FMT_LEFT_JUSTIFY)
		write_d_left(buf, &parts);
	else
		write_d_right(buf, &parts, f);
	return (buf + f->width);
}
