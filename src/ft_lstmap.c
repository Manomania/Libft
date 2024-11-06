/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:51:48 by maximart          #+#    #+#             */
/*   Updated: 2024/11/04 13:43:35 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*modified_lst;
	t_list	*modified_new;

	modified_lst = NULL;
	while (lst)
	{
		modified_new = ft_lstnew(f(lst->content));
		if (!modified_new)
		{
			ft_lstclear(&modified_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&modified_lst, modified_new);
		lst = lst->next;
	}
	return (modified_lst);
}
