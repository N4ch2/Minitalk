/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lengnum.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:17:07 by joramire          #+#    #+#             */
/*   Updated: 2023/01/01 21:54:34 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void		ft_print_nbr(long long int nbr, char *base, int nbase, int *c);
bool		ft_sign(char *str);
bool		ft_samechar(char *str);

void	ft_count_nbr(long long int nbr, char *base, int nbase, int *c)
{
	long long int	div;
	long long int	mod;

	mod = nbr % nbase;
	div = nbr / nbase;
	if (div != 0)
		ft_count_nbr(div, base, nbase, c);
	if (mod < 0)
		mod = -mod;
	*c = *c + 1;
}

int	ft_printf_lengnum(long long int nbr, char *base, int swch)
{
	long long int	nbase;
	int				c;

	c = 0;
	if (nbr == 0)
		return (0);
	if (!((int)ft_strlen(base) <= 1 || ft_samechar(base) || ft_sign(base)))
	{
		nbase = (int)ft_strlen(base);
		if (nbr < 0 && swch == 1)
			c += 1;
		ft_count_nbr(nbr, base, nbase, &c);
		return (c);
	}
	return (-1);
}
