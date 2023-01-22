/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flength.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:00:43 by joramire          #+#    #+#             */
/*   Updated: 2022/11/01 13:08:49 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

int	ft_printf_flength(const char *str)
{
	int	i;

	i = 0;
	while (!ft_printf_is_type(str[i]))
		i++;
	return (i + 1);
}
