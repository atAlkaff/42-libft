/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_len_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:11:27 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/18 19:59:10 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

size_t	conv_len_p(const t_format *f, const void *p)
{
	size_t	len;

	len = count_digits_16((uintptr_t)p) + 2;
	if (len < f->width)
		len = f->width;
	return (len);
}
