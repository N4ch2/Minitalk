/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:40:19 by joramire          #+#    #+#             */
/*   Updated: 2022/09/27 11:37:33 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	init_size_dst;
	size_t	max;

	init_size_dst = ft_strlen(dst);
	max = dstsize - ft_strlen(dst) - 1;
	i = 0;
	if (init_size_dst >= dstsize || dstsize == 0)
		return (ft_strlen(src) + dstsize);
	while (i < max && src[i] != '\0')
	{
		dst[init_size_dst + i] = src[i];
		i++;
	}
	dst[init_size_dst + i] = '\0';
	return (init_size_dst + ft_strlen(src));
}
