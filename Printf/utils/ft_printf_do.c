/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:22:11 by joramire          #+#    #+#             */
/*   Updated: 2022/11/11 11:40:29 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	ft_aux_do_lett(char c, t_pinfo *info)
{
	if (c == 'c')
		ft_printf_char(info);
	else
		ft_printf_string(info);
}

int	ft_printf_do(const char *format, t_pinfo *info)
{
	int	i;
	int	r;

	i = 0;
	r = ft_printf_flength(format);
	ft_printf_format((char *) format, info);
	while (!ft_printf_is_type(format[i]))
		i++;
	if (format[i] == 'c' || format[i] == 's')
		ft_aux_do_lett(format[i], info);
	else if (format[i] == 'p')
		ft_printf_pointer(info);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_printf_integer(info);
	else if (format[i] == 'u')
		ft_printf_unsigned(info);
	else if (format[i] == 'x')
		ft_printf_hex(info);
	else if (format[i] == 'X')
		ft_printf_hexa(info);
	else if (format[i] == '%')
		ft_printf_percentage(info);
	ft_printf_init(info);
	return (r);
}
