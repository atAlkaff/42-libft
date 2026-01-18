/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:19:59 by aalkaff           #+#    #+#             */
/*   Updated: 2025/10/28 21:30:43 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @internal Rabin-Karp string searching algorithm.
 * O(n + m) time where n and m are the lengths of the strings.
 * O(1) space.
 */

/**
 * @internal
 * @brief The number of possible characters (2^8).
 */
#define RK_BASE	256

/**
 * @internal
 * @brief Large prime number to avoid hash collisions.
 */
#define RK_MOD	1000003

/**
 * @internal
 * @brief Calculates the initial hash for the needle and its 'power' value.
 *
 * @param needle The string to hash.
 * @param hash A pointer to store the resulting hash of the needle.
 * @param power A pointer to store the calculated power
 * (RK_BASE ^ (needle_len - 1) % RK_MOD).
 * @return size_t   The length of the needle.
 */
static size_t	hash_needle(const char *needle,
	unsigned long *hash, unsigned long *power)
{
	size_t		len;

	*hash = 0;
	len = 0;
	*power = 1;
	while (needle[len])
	{
		*hash = (*hash * RK_BASE + (unsigned char)needle[len]) % RK_MOD;
		if (len > 0)
			*power = (*power * RK_BASE) % RK_MOD;
		len++;
	}
	return (len);
}

/**
 * @internal
 * @brief Calculates the initial hash for the first @p needle_len characters
 * of the haystack.
 *
 * @param haystack The string to search in.
 * @param needle_len The length of the needle (window size).
 * @return unsigned long The hash of the first @p needle_len characters.
 */
static unsigned long	initialize_hay_hash(const char *haystack,
	size_t needle_len)
{
	unsigned long	hash;
	size_t			i;

	hash = 0;
	i = 0;
	while (i < needle_len)
	{
		hash = (hash * RK_BASE + (unsigned char)haystack[i]) % RK_MOD;
		i++;
	}
	return (hash);
}

/**
 * @internal
 * @brief Efficiently "rolls" the hash one character to the right.
 *
 * @param hash The current hash value of the haystack window.
 * @param haystack A pointer to the start of the current window in the
 * haystack.
 * @param needle_len The length of the needle (window size).
 * @param power The pre-calculated power value for the hash.
 * @return unsigned long The new hash value for the window shifted one
 * character to the right.
 */
static unsigned long	roll_hay_hash(unsigned long hash,
	const char *haystack, size_t needle_len, unsigned long power)
{
	unsigned char	char_out;
	unsigned char	char_in;

	char_out = (unsigned char)haystack[0];
	char_in = (unsigned char)haystack[needle_len];
	hash = (hash + RK_MOD - (char_out * power) % RK_MOD) % RK_MOD;
	hash = (hash * RK_BASE + char_in) % RK_MOD;
	return (hash);
}

/**
 * @internal
 * @brief Measures the length of @p , up to a maximum of @p n bytes.
 *
 * @param s The string to measure.
 * @param n The maximum number of bytes to check.
 * @return size_t The length of the string @p s (if a null-terminator is
 * found within @p n bytes), or @p n if no null-terminator
 * is found.
 */
static size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] && i < n)
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t			need_len;
	size_t			i;
	unsigned long	need_hash;
	unsigned long	hay_hash;
	unsigned long	power;

	if (!*needle)
		return ((char *)haystack);
	need_len = hash_needle(needle, &need_hash, &power);
	n = ft_strnlen(haystack, n);
	if (need_len > n)
		return (NULL);
	hay_hash = initialize_hay_hash(haystack, need_len);
	i = 0;
	while (i + need_len <= n)
	{
		if (hay_hash == need_hash)
			if (ft_strncmp(haystack + i, needle, need_len) == 0)
				return ((char *)(haystack + i));
		if (i + need_len == n)
			break ;
		hay_hash = roll_hay_hash(hay_hash, haystack + i, need_len, power);
		i++;
	}
	return (NULL);
}
