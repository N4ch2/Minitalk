/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:33:31 by joramire          #+#    #+#             */
/*   Updated: 2022/09/30 19:37:57 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits(int n)
{
	int	counter;

	if (n < 0)
		n = (-1) * n;
	counter = 1;
	while (n / 10 != 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}

static char	*ft_exception(void)
{
	char	*buff;
	int		i;
	size_t	n;

	n = 2147483648;
	buff = (char *)malloc(12 * sizeof(char));
	if (buff == NULL)
		return (NULL);
	i = 11;
	buff[0] = '-';
	buff[i] = '\0';
	i--;
	while (i > 0)
	{
		buff[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (buff);
}

static void	ft_neg_setup(int *n, int *size, int *i)
{
	*size += 1;
	*n *= (-1);
	*i = 1;
}

static void	ft_fill_buff(int i, int stop, char *buff, int n)
{
	buff[i] = '\0';
	i--;
	while (i >= stop)
	{
		buff[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*buff;
	int		size;
	int		i;
	int		stop;

	if (n == -2147483648)
		return (ft_exception());
	size = ft_digits(n) + 1;
	i = 0;
	if (n < 0)
		ft_neg_setup(&n, &size, &i);
	buff = (char *)malloc(size * sizeof(char));
	if (buff == NULL)
		return (NULL);
	if (i == 1)
		buff[0] = '-';
	stop = i;
	i = size - 1;
	ft_fill_buff(i, stop, buff, n);
	return (buff);
}
