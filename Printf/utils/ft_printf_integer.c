/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:55:37 by joramire          #+#    #+#             */
/*   Updated: 2023/01/03 13:05:01 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"
#include <stdio.h>
/*
Hastag(#) flag no work
*/

void	ft_aux_integer_width(int n, t_pinfo *info)
{
	if (n >= 0 && info -> sign == 1)
		info -> width--;
	if (info -> dash == 1)
	{
		if (n < 0)
			info -> alng += write(1, "-", 1);
		if (n >= 0 && info -> sign == 1)
			info -> alng += write(1, "+", 1);
		info -> alng += ft_printf_putnbr_base(n, "0123456789");
	}
	if (ft_printf_lengnum(n, "0123456789", 1) == 0)
		info -> width -= 1;
	while (info -> width > ft_printf_lengnum(n, "0123456789", 1))
	{
		info -> alng += write(1, " ", 1);
		info -> width -= 1;
	}
	if (info -> dash == 0)
	{
		if (n < 0)
			info -> alng += write(1, "-", 1);
		if (n >= 0 && info -> sign == 1)
			info -> alng += write(1, "+", 1);
		info -> alng += ft_printf_putnbr_base(n, "0123456789");
	}
}

void	ft_aux_integer_zero(int n, t_pinfo *info)
{
	if (n == 0)
		info -> width -= 1;
	if (n >= 0 && info -> sign == 1)
		info -> width--;
	if (n < 0)
			info -> alng += write(1, "-", 1);
	if (n >= 0 && info -> sign == 1)
			info -> alng += write(1, "+", 1);
	while (info -> width > ft_printf_lengnum(n, "0123456789", 1))
	{
		info -> alng += write(1, "0", 1);
		info -> width -= 1;
	}
	if (info -> dash == 0)
		info -> alng += ft_printf_putnbr_base(n, "0123456789");
}

void	ft_aux_integer_prc(int n, t_pinfo *info, int aux)
{
	int	max;
	int	length_num;

	aux = info -> prc;
	length_num = ft_printf_lengnum(n, "0123456789", 1);
	max = ft_integer_max(aux, length_num);
	if (n == 0)
		info -> prc -= 1;
	if (info -> sign == 1 || n < 0)
		info -> width -= 1;
	if (n < 0 && max != aux)
		max -= 1;
	if (info -> dash == 0 || info -> zero == 1)
		ft_printf_integer_space(info, max);
	if (n < 0)
			info -> alng += write(1, "-", 1);
	if (n >= 0 && info -> sign == 1)
			info -> alng += write(1, "+", 1);
	if (n < 0 && info -> prc == length_num)
		info -> prc += 1;
	ft_printf_integer_zeros(info, length_num, n, aux);
	if (!(n == 0 && aux == 0))
		info -> alng += ft_printf_putnbr_base(n, "0123456789");
	if (info -> dash == 1 || info -> zero == 1)
		ft_printf_integer_space(info, max);
}

void	ft_aux_integer_space(int n, t_pinfo *info)
{
	if (info -> width == 0 && info -> prc == 0)
	{
		info -> alng += write(1, " ", 1);
		if (n > 0 && info -> sign == 1)
			info -> alng += write(1, "+", 1);
		if (!(n == 0 && info -> prc == 0 && info -> point == 1))
			info -> alng += ft_printf_putnbr_base(n, "0123456789");
	}
	else
	{
		if (info -> dash == 0 || info -> space == 1)
		{
			info -> alng += write(1, " ", 1);
			info -> width--;
		}
		if (info -> point == 1)
			ft_aux_integer_prc(n, info, 0);
		else if (info -> dash == 1)
			ft_aux_integer_width(n, info);
		else if (info -> zero == 1)
			ft_aux_integer_zero(n, info);
		else
			ft_aux_integer_width(n, info);
	}
}

void	ft_printf_integer(t_pinfo *info)
{
	int		n;

	n = va_arg(info -> arg, int);
	if (n >= 0 && info -> space == 1)
		ft_aux_integer_space(n, info);
	else if (info -> point == 1)
		ft_aux_integer_prc(n, info, 0);
	else if (info -> zero == 1)
		ft_aux_integer_zero(n, info);
	else if (info -> width != 0)
		ft_aux_integer_width(n, info);
	else
	{
		if (n < 0)
			info -> alng += write(1, "-", 1);
		if (n >= 0 && info -> sign == 1)
			info -> alng += write(1, "+", 1);
		info -> alng += ft_printf_putnbr_base(n, "0123456789");
	}
}
