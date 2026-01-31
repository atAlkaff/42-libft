/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:00:38 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/31 18:52:22 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define FT_GETERRNO 0
#define FT_SETERRNO 1

static int	ft_errno(int mode, int err)
{
	static int	code;

	if (mode == FT_GETERRNO)
		return (code);
	if (mode == FT_SETERRNO)
	{
		code = err;
		return (code);
	}
	return (0);
}

int	ft_geterrno(void)
{
	return (ft_errno(FT_GETERRNO, 0));
}

void	ft_seterrno(int err)
{
	ft_errno(FT_SETERRNO, err);
}
