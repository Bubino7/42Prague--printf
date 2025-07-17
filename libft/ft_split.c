/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbubak <jbubak@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:48:50 by jbubak            #+#    #+#             */
/*   Updated: 2025/06/16 19:16:08 by jbubak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	word_count;
	size_t	i;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			word_count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word_count);
}

char	*ft_extract_word(char const *s, char c, size_t *i)
{
	char	*word;
	size_t	word_start;

	while (s[*i] && s[*i] == c)
		(*i)++;
	if (s[*i])
	{
		word_start = *i;
		while (s[*i] && s[*i] != c)
			(*i)++;
		word = malloc(sizeof(char) * (*i - word_start + 1));
		if (!word)
			return (NULL);
		ft_strlcpy(word, s + word_start, *i - word_start + 1);
		return (word);
	}
	word = malloc(sizeof(char));
	if (!word)
		return (NULL);
	word[0] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	result = malloc((sizeof(char *) * (ft_count_words(s, c) + 1)));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < ft_count_words(s, c))
	{
		result[j] = ft_extract_word(s, c, &i);
		if (!result[j])
		{
			while (j > 0)
				free(result[--j]);
			free(result);
			return (NULL);
		}
		j++;
	}
	result[j] = NULL;
	return (result);
}
