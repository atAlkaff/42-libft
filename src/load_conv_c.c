/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_conv_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:16:44 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/18 19:53:33 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*load_conv_c(char *buf, const t_format *f, char c)
{
	if (f->width <= 1)
	{
		buf[0] = c;
		return (buf + 1);
	}
	if (f->flags & FMT_LEFT_JUSTIFY)
	{
		buf[0] = c;
		ft_memset(buf + 1, ' ', f->width - 1);
	}
	else
	{
		ft_memset(buf, ' ', f->width - 1);
		buf[f->width - 1] = c;
	}
	return (buf + f->width);
}
