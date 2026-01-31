/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:24:08 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/31 20:45:28 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *elem)
{
	if (!lst || !elem)
		return ;
	elem->next = *lst;
	*lst = elem;
}

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
