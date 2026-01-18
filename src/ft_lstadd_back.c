/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:25:44 by aalkaff           #+#    #+#             */
/*   Updated: 2025/10/29 22:27:09 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *elem)
{
	if (!lst || !elem)
		return ;
	elem->next = NULL;
	if (!*lst)
		*lst = elem;
	else
		ft_lstlast(*lst)->next = elem;
}
