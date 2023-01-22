/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:56:54 by joramire          #+#    #+#             */
/*   Updated: 2022/09/23 18:53:12 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		out;

	i = 0;
	out = 0;
	while (i < n && s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (s1[i] != s2[i] && n != 0 && i != n)
		out = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (out);
}
