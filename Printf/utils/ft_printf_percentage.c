/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percentage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:53:53 by joramire          #+#    #+#             */
/*   Updated: 2022/12/28 18:21:35 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	ft_aux_percentage_width(t_pinfo *info)
{
	if (info -> dash == 1)
		info -> alng += write(1, "%", 1);
	while (info -> width > 1)
	{
		info -> alng += write(1, " ", 1);
		info -> width -= 1;
	}
	if (info -> dash == 0)
		info -> alng += write(1, "%", 1);
}

void	ft_aux_percentage_zero(t_pinfo *info)
{
	if (info -> dash == 1)
		info -> alng += write(1, "%", 1);
	while (info -> width > 1)
	{
		info -> alng += write(1, " ", 1);
		info -> width -= 1;
	}
	if (info -> dash == 0)
		info -> alng += write(1, "%", 1);
}

void	ft_printf_percentage(t_pinfo *info)
{
	if (info -> zero == 1)
		ft_aux_percentage_zero(info);
	else if (info -> width != 0)
		ft_aux_percentage_width(info);
	else
		info -> alng += write(1, "%", 1);
}
