/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:53:37 by joramire          #+#    #+#             */
/*   Updated: 2023/01/01 22:11:44 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	ft_aux_unsigned_width(unsigned int n, t_pinfo *info)
{
	if (info -> dash == 1)
		info -> alng += ft_printf_putnbr_base(n, "0123456789");
	if (n == 0)
		info -> width -= 1;
	while (info -> width > ft_printf_lengnum(n, "0123456789", 0))
	{
		info -> alng += write(1, " ", 1);
		info -> width -= 1;
	}
	if (info -> dash == 0)
		info -> alng += ft_printf_putnbr_base(n, "0123456789");
}

void	ft_aux_unsigned_zero(unsigned int n, t_pinfo *info)
{
	if (n == 0)
		info -> width -= 1;
	while (info -> width > ft_printf_lengnum(n, "0123456789", 0))
	{
		info -> alng += write(1, "0", 1);
		info -> width -= 1;
	}
	if (info -> dash == 0)
		info -> alng += ft_printf_putnbr_base(n, "0123456789");
}

void	ft_aux_unsigned_prc(unsigned int n, t_pinfo *info, int aux)
{
	int	max;

	aux = info -> prc;
	max = ft_integer_max(aux, ft_printf_lengnum(n, "0123456789", 0));
	if (n == 0 && info -> prc == 0)
		info -> prc -= 1;
	if (info -> dash == 0 || info -> zero == 1)
		ft_printf_integer_space(info, max);
	while (info -> prc > ft_printf_lengnum(n, "0123456789", 0))
	{
		info -> alng += write(1, "0", 1);
		info -> prc -= 1;
	}
	if (!(n == 0 && aux * (info -> prc) == 0))
		info -> alng += ft_printf_putnbr_base(n, "0123456789");
	if (info -> dash == 1 || info -> zero == 1)
		ft_printf_integer_space(info, max);
}

void	ft_printf_unsigned(t_pinfo *info)
{
	unsigned int	n;

	n = va_arg(info -> arg, int);
	if (info -> point == 1)
		ft_aux_unsigned_prc(n, info, 0);
	else if (info -> zero == 1)
		ft_aux_unsigned_zero(n, info);
	else if (info -> width != 0)
		ft_aux_unsigned_width(n, info);
	else
		info -> alng += ft_printf_putnbr_base(n, "0123456789");
}
