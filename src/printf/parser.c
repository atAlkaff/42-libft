/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:46:10 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/03 23:31:50 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static const char	*parse_flags(const char *s, t_format *f)
{
	while (*s)
	{
		if (*s == '-')
			f->flags |= FMT_LEFT_JUSTIFY;
		else if (*s == '0')
			f->flags |= FMT_ZERO_PAD;
		else if (*s == ' ')
			f->flags |= FMT_PLUS_SIGN_SPACE;
		else if (*s == '+')
			f->flags |= FMT_PLUS_SIGN_SHOW;
		else if (*s == '#')
			f->flags |= FMT_ALT_FORM;
		else
			break ;
		s++;
	}
	return (s);
}

static const char	*parse_width(const char *s, t_format *f, va_list ap)
{
	int	width;

	if (*s == '*')
	{
		width = va_arg(ap, int);
		if (width < 0)
		{
			f->flags |= FMT_LEFT_JUSTIFY;
			width = -width;
		}
		f->width = width;
		return (s + 1);
	}
	f->width = 0;
	while (ft_isdigit(*s))
	{
		f->width = f->width * 10 + (*s - '0');
		s++;
	}
	return (s);
}

static const char	*parse_precision(const char *s, t_format *f, va_list ap)
{
	int	precision;

	if (*s != '.')
		return (s);
	s++;
	f->flags |= FMT_PRECISION_ON;
	if (*s == '*')
	{
		precision = va_arg(ap, int);
		if (precision < 0)
			f->flags &= ~FMT_PRECISION_ON;
		else
			f->precision = precision;
		return (s + 1);
	}
	f->precision = 0;
	while (ft_isdigit(*s))
	{
		f->precision = f->precision * 10 + (*s - '0');
		s++;
	}
	return (s);
}

const char	*parse_format(const char *s, t_format *f, va_list args)
{
	ft_memset(f, 0, sizeof(*f));
	s = parse_flags(s, f);
	if (*s != '.')
		s = parse_width(s, f, args);
	s = parse_precision(s, f, args);
	if (ft_strchr("cspdiuxX%", *s))
	{
		f->specifier = *s;
		s++;
	}
	return (s);
}
