/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype_class.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:13:00 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/18 20:16:30 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((unsigned)((c | 32) - 'a') < 26
		|| (unsigned)(c - '0') < 10);
}

int	ft_isalpha(int c)
{
	return ((unsigned)((c | 32) - 'a') < 26);
}

int	ft_isascii(int c)
{
	return ((unsigned)c <= 127);
}

int	ft_isdigit(int c)
{
	return ((unsigned)(c - '0') < 10);
}

int	ft_isprint(int c)
{
	return ((unsigned)(c - 32) < 95);
}
