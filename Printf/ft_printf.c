/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:07:32 by joramire          #+#    #+#             */
/*   Updated: 2022/11/01 14:30:32 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/libutils.h"

int	ft_printf(const char *str, ...)
{
	t_pinfo	*info;
	int		i;
	int		counter;

	info = (t_pinfo *)malloc(sizeof(t_pinfo));
	if (info == NULL)
		return (-1);
	ft_printf_init(info);
	va_start(info -> arg, str);
	i = -1;
	counter = 0;
	info -> alng = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
			i += ft_printf_do((str + (i + 1)), info);
		else
			counter += write(1, &str[i], 1);
	}
	va_end(info -> arg);
	counter += info -> alng;
	free(info);
	return (counter);
}
