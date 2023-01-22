/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:31:02 by joramire          #+#    #+#             */
/*   Updated: 2022/09/28 12:43:54 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	size_t	sum;
	char	*buff;

	sum = start + len;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (sum > ft_strlen(s))
		len = ft_strlen(s) - start;
	size = len + 1;
	buff = (char *)malloc(size * sizeof(char));
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buff[i] = s[start + i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
