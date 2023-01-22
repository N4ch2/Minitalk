/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:41:23 by joramire          #+#    #+#             */
/*   Updated: 2022/11/01 17:43:17 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	ft_printf_init(t_pinfo *info)
{
	info -> width = 0;
	info -> zero = 0;
	info -> point = 0;
	info -> prc = 0;
	info -> dash = 0;
	info -> sign = 0;
	info -> space = 0;
}
