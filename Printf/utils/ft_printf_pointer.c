/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:54:36 by joramire          #+#    #+#             */
/*   Updated: 2022/12/31 18:29:40 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

/*
Plus(+), Space( ), Hastag(#), Point(.) and Zero(0) flag no work
*/

void	ft_printf_pointer(t_pinfo *info)
{
	unsigned long int	p;

	p = va_arg(info -> arg, unsigned long long);
	if (info -> dash == 1)
	{
		info -> alng += write(1, "0x", 2);
		info -> alng += ft_aux_point_putnbr(p, "0123456789abcdef");
	}
	if (!p)
		info -> width -= 1;
	while (info -> width > (2 + ft_aux_point_lengnbr(p, "0123456789abcdef", 1)))
	{
		info -> alng += write(1, " ", 1);
		info -> width -= 1;
	}
	if (info -> dash == 0)
	{
		info -> alng += write(1, "0x", 2);
		info -> alng += ft_aux_point_putnbr(p, "0123456789abcdef");
	}
}
