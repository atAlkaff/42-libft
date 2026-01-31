/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:29:39 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/31 20:45:56 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>	// free

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*node;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		prev = node;
		node = node->next;
		del(prev->content);
		free(prev);
	}
	*lst = NULL;
}
