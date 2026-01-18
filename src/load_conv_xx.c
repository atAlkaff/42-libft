/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_conv_xx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:44:04 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/18 19:54:47 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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
	if (f->width > total_len)
		p->pad_len = f->width - total_len;
	else
		p->pad_len = 0;
}

static void	write_xx_left(char *buf, t_hex_parts *p)
{
	ft_memcpy(buf, "0X", p->prefix_len);
	ft_xxtoa_stack(buf + p->prefix_len, p->value, p->num_len);
	ft_memset(buf + p->prefix_len + p->num_len, ' ', p->pad_len);
}

static void	write_xx_right(char *buf, t_hex_parts *p, const t_format *f)
{
	if ((f->flags & FMT_ZERO_PAD) && !(f->flags & FMT_PRECISION_ON))
	{
		ft_memcpy(buf, "0X", p->prefix_len);
		ft_memset(buf + p->prefix_len, '0', p->pad_len);
		ft_xxtoa_stack(buf + p->prefix_len + p->pad_len, p->value, p->num_len);
	}
	else
	{
		ft_memset(buf, ' ', p->pad_len);
		ft_memcpy(buf + p->pad_len, "0X", p->prefix_len);
		ft_xxtoa_stack(buf + p->pad_len + p->prefix_len, p->value, p->num_len);
	}
}

char	*load_conv_xx(char *buf, const t_format *f, unsigned int u)
{
	t_hex_parts	parts;
	size_t		total_len;

	init_hex_parts(&parts, f, u);
	total_len = parts.num_len + parts.prefix_len;
	if (parts.pad_len == 0)
	{
		ft_memcpy(buf, "0X", parts.prefix_len);
		ft_xxtoa_stack(buf + parts.prefix_len, parts.value, parts.num_len);
		return (buf + total_len);
	}
	if (f->flags & FMT_LEFT_JUSTIFY)
		write_xx_left(buf, &parts);
	else
		write_xx_right(buf, &parts, f);
	return (buf + f->width);
}
