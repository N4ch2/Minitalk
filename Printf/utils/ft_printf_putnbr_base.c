/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:15:29 by joramire          #+#    #+#             */
/*   Updated: 2022/11/04 13:20:20 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

bool	ft_samechar(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[j] == str[i])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	ft_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 43 || str[i] == 45)
			return (true);
		i++;
	}
	return (false);
}

void	ft_print_nbr(long long int nbr, char *base, int nbase, int *c)
{
	long long int	div;
	long long int	mod;

	mod = nbr % nbase;
	div = nbr / nbase;
	if (div != 0)
		ft_print_nbr(div, base, nbase, c);
	if (mod < 0)
		mod = -mod;
	*c = *c + write(1, &base[mod], 1);
}

int	ft_printf_putnbr_base(long long int nbr, char *base)
{
	long long int	nbase;
	int				c;

	c = 0;
	if (!((int)ft_strlen(base) <= 1 || ft_samechar(base) || ft_sign(base)))
	{
		nbase = (int)ft_strlen(base);
		ft_print_nbr(nbr, base, nbase, &c);
		return (c);
	}
	return (-1);
}
