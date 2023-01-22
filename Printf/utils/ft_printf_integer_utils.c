/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:16:42 by joramire          #+#    #+#             */
/*   Updated: 2023/01/02 15:02:01 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"
#include <stdio.h>

int	ft_integer_max(int n, int m)
{
	if (n > m)
		return (n);
	else
		return (m);
}

void	ft_printf_integer_space(t_pinfo *info, int max)
{
	while (info -> width > max)
	{
		info -> alng += write(1, " ", 1);
		info -> width -= 1;
	}
}

void	ft_printf_integer_zeros(t_pinfo *info, int length_num, int n, int aux)
{
	while (info -> prc > length_num)
	{
		info -> alng += write(1, "0", 1);
		info -> prc -= 1;
	}
	if (n < 0 && aux > length_num)
		info -> alng += write(1, "0", 1);
}
