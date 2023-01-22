/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:44:34 by joramire          #+#    #+#             */
/*   Updated: 2022/09/27 18:01:16 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;

	out = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	ft_strlcpy(out, (char *)s1, ft_strlen(s1) + 1);
	return (out);
}
