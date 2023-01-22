/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joramire <joramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:37:14 by joramire          #+#    #+#             */
/*   Updated: 2022/09/30 19:42:49 by joramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_number_of_words(char const *s, char c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			size++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (size);
}

static char	**ft_clean(char **list, size_t i)
{
	while (i >= 0)
	{
		free(list[i]);
		list[i] = 0;
		if (i == 0)
		{
			free(list);
			return (NULL);
		}
		i--;
	}
	return (NULL);
}

static void	ft_set_word(char const *s, size_t *st, size_t *end, char c)
{
	while (s[*st] == c && s[*st] != '\0')
		*st = *st + 1;
	*end = *st;
	while (s[*end] != c && s[*end] != '\0')
		*end = *end + 1;
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	size_t	st;
	size_t	end;
	size_t	i;

	list = (char **)malloc((ft_number_of_words(s, c) + 1) * sizeof(char *));
	if (list == NULL)
		return (NULL);
	st = 0;
	i = 0;
	while (s[st] != '\0')
	{
		ft_set_word(s, &st, &end, c);
		if (end != st)
		{
			list[i] = ft_substr(s, st, (end - st));
			if (list[i] == NULL)
				return (ft_clean(list, i));
			i++;
		}
		st = end;
	}
	list[i] = NULL;
	return (list);
}
