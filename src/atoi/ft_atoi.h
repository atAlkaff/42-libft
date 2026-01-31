/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:11:44 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/31 18:53:01 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATOI_H
# define FT_ATOI_H

typedef struct s_atoi_parts
{
	const char		*nptr;
	long			result;
	unsigned int	base;
	int				sign;
}	t_atoi_parts;

void	initialize_atoi_struct(t_atoi_parts *atoi_struct,
			const char *nptr, unsigned int base);

int		get_digit_value(char c);

#endif
