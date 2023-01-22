/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_is_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:57:46 by joramire          #+#    #+#             */
/*   Updated: 2022/10/30 17:55:26 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

bool	ft_printf_is_type(char c)
{
	bool	out;

	out = false;
	if (c == 'c' || c == 's')
		out = true;
	else if (c == 'p' || c == 'd')
		out = true;
	else if (c == 'i' || c == 'u')
		out = true;
	else if (c == 'x' || c == 'X' || c == '%')
		out = true;
	return (out);
}
