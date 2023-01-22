/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:09:18 by joramire          #+#    #+#             */
/*   Updated: 2023/01/03 12:49:21 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	ft_aux_string_width(char *str, t_pinfo *info)
{
	if (info -> dash == 1)
		ft_putstr_fd(str, 1);
	while (info -> width > (int)ft_strlen(str))
	{
		info -> alng += write(1, " ", 1);
		info -> width -= 1;
	}
	if (info -> dash == 0)
		ft_putstr_fd(str, 1);
	info -> alng += ft_strlen(str);
}

void	ft_aux_string_prc(char *str, t_pinfo *info)
{
	char	*aux_str;

	aux_str = NULL;
	if ((int)ft_strlen(str) > info -> prc)
	{
		aux_str = ft_substr(str, 0, info -> prc);
		str = aux_str;
	}
	if (info -> dash == 1)
		ft_putstr_fd(str, 1);
	while (info -> width > (int)ft_strlen(str) && info -> zero == 0)
	{
		info -> alng += write(1, " ", 1);
		info -> width -= 1;
	}
	if (info -> dash == 0)
		ft_putstr_fd(str, 1);
	info -> alng += ft_strlen(str);
	free(aux_str);
}

void	ft_aux_string_null(t_pinfo *info)
{
	int	length;

	if (info -> prc < 6 && info -> point == 1)
		length = info -> prc;
	else
		length = 6;
	if (info -> dash == 1)
		info -> alng += write(1, "(null)", length);
	while (info -> width > length && info -> zero == 0)
	{
		info -> alng += write(1, " ", 1);
		info -> width -= 1;
	}
	if (info -> dash == 0)
		info -> alng += write(1, "(null)", length);
}

void	ft_aux_string_empty(t_pinfo *info)
{
	while (info -> width > 0 && info -> zero == 0)
	{
		info -> alng += write(1, " ", 1);
		info -> width -= 1;
	}
}

void	ft_printf_string(t_pinfo *info)
{
	char	*str;

	str = va_arg(info -> arg, char *);
	if (str == NULL)
		ft_aux_string_null(info);
	else if (*str == '\0')
		ft_aux_string_empty(info);
	else if (info -> point == 1)
		ft_aux_string_prc(str, info);
	else
		ft_aux_string_width(str, info);
}
