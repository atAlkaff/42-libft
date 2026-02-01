/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:06:18 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/01 20:12:30 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>	// write

void	ft_putstr_fd(char *s, int fd)
{
	ssize_t	bytes;

	if (!s)
		return ;
	bytes = write(fd, s, ft_strlen(s));
	(void)bytes;
}

void	ft_putendl_fd(char *s, int fd)
{
	ssize_t	bytes;

	if (!s)
		return ;
	bytes = write(fd, s, ft_strlen(s));
	bytes += write(fd, "\n", 1);
	(void)bytes;
}
