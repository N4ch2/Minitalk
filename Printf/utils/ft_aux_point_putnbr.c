/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_point_putnbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:50:47 by joramire          #+#    #+#             */
/*   Updated: 2022/11/11 10:50:51 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

bool		ft_sign(char *str);
bool		ft_samechar(char *str);

void	ft_pprintnbr(unsigned long long nbr, char *base, int nbase, int *c)
{
	unsigned long long	div;
	unsigned long long	mod;

	mod = nbr % nbase;
	div = nbr / nbase;
	if (div != 0)
		ft_pprintnbr(div, base, nbase, c);
	if (mod < 0)
		mod = -mod;
	*c = *c + write(1, &base[mod], 1);
}

int	ft_aux_point_putnbr(unsigned long long nbr, char *base)
{
	unsigned long long	nbase;
	int					c;

	c = 0;
	if (!((int)ft_strlen(base) <= 1 || ft_samechar(base) || ft_sign(base)))
	{
		nbase = (int)ft_strlen(base);
		ft_pprintnbr(nbr, base, nbase, &c);
		return (c);
	}
	return (-1);
}
