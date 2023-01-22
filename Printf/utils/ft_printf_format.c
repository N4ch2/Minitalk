/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:15:03 by joramire          #+#    #+#             */
/*   Updated: 2023/01/02 15:36:16 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	ft_aux_format_spaces(char *format, t_pinfo *info, int *i)
{
	info -> space = 1;
	while (format[*i] == ' ')
		*i = *i + 1;
}

void	ft_aux_format_width(char *format, t_pinfo *info, int *i)
{
	int	c;

	if (format[0] == '-')
		info -> dash = 1;
	else if (format[0] == '0')
		info -> zero = 1;
	else if (format[0] == '+')
		info -> sign = 1;
	info -> width = ft_printf_getprc(format + 1);
	if (format[1] == ' ')
		info -> space = 1;
	if (!(format[0] == '+' && format[1] == '0'))
	{
		c = 1;
		while (format[c] == '0' || format[c] == ' ')
			c += 1;
		*i = *i + ft_printf_lengnum(info -> width, "0123456789", 0) + (c - 1);
	}
}

void	ft_aux_format_prc(char *format, t_pinfo *info, int *i)
{
	info -> point = 1;
	info -> prc = ft_printf_getprc(format + 1);
	*i = *i + ft_printf_lengnum(info -> prc, "0123456789", 0);
	if (info -> prc == 0 && !ft_printf_is_type(format[1]))
		*i += 1;
}

void	ft_printf_format(char *format, t_pinfo *info)
{
	int	i;

	i = 0;
	info -> width = ft_printf_getprc(format);
	if (format[i] == ' ')
		ft_aux_format_spaces(format, info, &i);
	if (info -> width != 0 && format[i] != '0')
		i += ft_printf_lengnum(info -> width, "0123456789", 0);
	while (!ft_printf_is_type(format[i]))
	{
		if (format[i] == '-' || format[i] == '0')
			ft_aux_format_width(format + i, info, &i);
		else if (format[i] == '.')
			ft_aux_format_prc(format + i, info, &i);
		else if (format[i] == '+')
			ft_aux_format_width(format + i, info, &i);
		else if (format[i] == '#')
		{
			info -> hastag = 1;
			info -> width = ft_printf_getprc(format + (i + 1));
			if (info -> width != 0 && format[i + 1] != '0')
				i += ft_printf_lengnum(info -> width, "0123456789", 0);
		}
		i++;
	}
}
