/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:55:20 by joramire          #+#    #+#             */
/*   Updated: 2022/11/11 12:01:42 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

/*
Zero(0), Precision(.), Hastag(#), Space( ) and Plus(+) flag no work
*/

void	ft_printf_char(t_pinfo *info)
{
	char	c;

	c = va_arg(info -> arg, int);
	if (info -> dash == 1)
		info -> alng += write(1, &c, 1);
	while (info -> width > 1)
	{
		info -> alng += write(1, " ", 1);
		info -> width -= 1;
	}
	if (info -> dash == 0)
		info -> alng += write(1, &c, 1);
}
