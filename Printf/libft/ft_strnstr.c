/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:42:14 by joramire          #+#    #+#             */
/*   Updated: 2022/09/27 16:47:14 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	comp;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && *haystack != '\0')
	{
		comp = ft_strncmp(haystack, needle, ft_strlen(needle));
		if (comp == 0 && (i + ft_strlen(needle)) <= len)
			return ((char *)haystack);
		i++;
		haystack++;
	}
	if (i == len || *haystack == '\0')
		return (NULL);
	return ((char *)haystack);
}
