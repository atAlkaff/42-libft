/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_conv_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:16:44 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/01 19:09:35 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*load_conv_c(char *buf, size_t n, const t_format *f, char c)
{
	size_t	pad_len;
	size_t	to_write;

	if (f->width <= 1)
	{
		buf[0] = c;
		return (buf + 1);
	}
	if (f->flags & FMT_LEFT_JUSTIFY)
	{
		buf[0] = c;
		to_write = min(f->width, n) - 1;
		ft_memset(buf + 1, ' ', to_write);
		return (buf + 1 + to_write);
	}
	pad_len = f->width - 1;
	to_write = min(pad_len, n);
	ft_memset(buf, ' ', to_write);
	if (n > pad_len)
	{
		buf[pad_len] = c;
		return (buf + pad_len + 1);
	}
	return (buf + to_write);
}
