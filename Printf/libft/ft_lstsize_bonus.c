/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:10:37 by joramire          #+#    #+#             */
/*   Updated: 2022/10/03 11:25:43 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;

	if (lst == NULL)
		return (0);
	counter = 1;
	while (lst -> next != NULL && lst != NULL)
	{
		counter++;
		lst = lst -> next;
	}
	return (counter);
}
