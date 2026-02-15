/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:30:12 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/15 15:19:36 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>	// malloc, free

/**
 * @internal
 * @brief Returns a pointer to the first occurrence of @p c in @p s
 * or to the end of @p s if it was not found.
 * @param s The string to search in.
 * @param c The character to search for.
 * @returns A pointer to the first occurrence of @p c in @p s
 * or to the end of @p s if it was not found.
 */
static char	*ft_strchrnul(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}

/**
 * @internal
 * @brief Counts the number of words in @p s, delimited by @p c
 * or by the end of @p s.
 * @param s The string to split.
 * @param c The delimiter character.
 * @returns The number of words in @p s.
 */
size_t	ft_count_words(const char *s, char c)
{
	size_t		nwords;
	const char	*end;

	nwords = 0;
	while (*s)
	{
		if (*s != c)
		{
			nwords++;
			end = ft_strchrnul(s, c);
			if (!*end)
				break ;
			s = end;
		}
		else
			s++;
	}
	return (nwords);
}

/**
 * @internal
 * @brief Loads the next word in @p s to @p word.
 * @param s The original string.
 * @param c The delimiter character.
 * @param word Output: a pointer to the allocated word.
 * @returns A pointer to the location in @p s after the end of
 * the word.
 */
static char	*get_next_word(const char *s, char c, char **word)
{
	char	*res;
	size_t	len;

	len = ft_strchrnul(s, c) - s;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s, len);
	res[len] = '\0';
	*word = res;
	return ((char *)(s + len));
}

/**
 * @internal
 * @brief Frees all words and the list of words on error.
 * @param words The null-terminated array of words.
 * @returns NULL
 */
static char	**free_words(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
		free(words[i]);
	free(words);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**words;
	size_t	i;

	if (!s)
		return (NULL);
	words = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			s = get_next_word(s, c, &words[i]);
			if (!words[i])
				return (free_words(words));
			i++;
		}
		else
			s++;
	}
	words[i] = NULL;
	return (words);
}
