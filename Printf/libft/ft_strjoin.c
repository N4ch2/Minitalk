/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:30:23 by joramire          #+#    #+#             */
/*   Updated: 2022/10/03 19:36:32 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	char	*buff;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	buff = (char *)malloc((size1 + size2 + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	ft_strlcpy(buff, (char *)s1, size1 + 1);
	ft_strlcat(buff, (char *)s2, size1 + size2 + 1);
	return (buff);
}
