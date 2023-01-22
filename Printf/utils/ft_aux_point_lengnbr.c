/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_point_lengnbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:50:59 by joramire          #+#    #+#             */
/*   Updated: 2022/11/11 10:52:57 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void		ft_pprintnbr(unsigned long long nbr, char *base, int nbase, int *c);
bool		ft_sign(char *str);
bool		ft_samechar(char *str);

void	ft_pcount_nbr(unsigned long long nbr, char *base, int nbase, int *c)
{
	unsigned long long	div;
	unsigned long long	mod;

	mod = nbr % nbase;
	div = nbr / nbase;
	if (div != 0)
		ft_pcount_nbr(div, base, nbase, c);
	if (mod < 0)
		mod = -mod;
	*c = *c + 1;
}

int	ft_aux_point_lengnbr(unsigned long long nbr, char *base, int swch)
{
	unsigned long long	nbase;
	int					c;

	c = 0;
	if (nbr == 0)
		return (0);
	if (!((int)ft_strlen(base) <= 1 || ft_samechar(base) || ft_sign(base)))
	{
		nbase = (int)ft_strlen(base);
		if (nbr < 0 && swch == 1)
			c += 1;
		ft_pcount_nbr(nbr, base, nbase, &c);
		return (c);
	}
	return (-1);
}
