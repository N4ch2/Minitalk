/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:19:34 by joramire          #+#    #+#             */
/*   Updated: 2022/10/03 18:35:01 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_f(void *content, void *(*f)(void *))
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node -> content = f(content);
	node -> next = NULL;
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*aux;

	if (lst == NULL)
		return (NULL);
	nlst = ft_f(lst -> content, f);
	lst = lst -> next;
	while (lst != NULL)
	{
		aux = ft_f(lst -> content, f);
		if (aux == NULL)
			ft_lstclear(&nlst, del);
		ft_lstadd_back(&nlst, aux);
		lst = lst -> next;
	}
	return (nlst);
}
