/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:20:39 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/18 20:21:01 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	c |= ((unsigned)(c - 'A') < 26) << 5;
	return (c);
}

int	ft_toupper(int c)
{
	c &= ~(((unsigned)(c - 'a') < 26) << 5);
	return (c);
}
