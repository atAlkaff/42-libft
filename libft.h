/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:47:55 by aalkaff           #+#    #+#             */
/*   Updated: 2025/08/21 19:35:25 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

// size_t and NULL
# include <stddef.h>

// Part 1 Functions

/**
 * For these functions, the caller is responsible for passing valid input.
 */

/**
 * @brief Checks if a character is alphabetical, without locale support.
 *
 * @param c The character to test.
 *
 * @return Whether `c` is alphabetical.
 * @retval 1 – `c` is alphabetical.
 * @retval 0 – `c` is not alphabetical.
 */
int		ft_isalpha(int c);

/**
 * @brief Checks if a character is numerical, without locale support.
 *
 * @param c The character to test.
 *
 * @return Whether `c` is a digit.
 * @retval 1 – `c` is a digit.
 * @retval 0 – `c` is not a digit.
 */
int		ft_isdigit(int c);

/**
 * @brief Checks if a character is alphanumeric, without locale support.
 *
 * @param c The character to test.
 *
 * @return Whether `c` is alphanumeric.
 * @retval 1 – `c` is alphanumeric.
 * @retval 0 – `c` is not alphanumeric.
 */
int		ft_isalnum(int c);

/**
 * @brief Checks if a character is in the ASCII character set [0, 127].
 *
 * @param c The character to test.
 *
 * @return Whether `c` is an ASCII code [0, 127].
 * @retval 1 – `c` is an ASCII code.
 * @retval 0 – `c` is not an ASCII code.
 */
int		ft_isascii(int c);

/**
 * @brief Checks if a character is printable, without locale support.
 *
 * @param c The character to test.
 *
 * @return Whether `c` is a printable ASCII character [32, 126].
 * @retval 1 – `c` is a printable ASCII character.
 * @retval 0 – `c` is not a printable ASCII character.
 */
int		ft_isprint(int c);

/**
 * @brief Returns the length of a string.
 *
 * @param s The null-terminated C string.
 *
 * @return The number of characters in `s`.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Sets the first `n` bytes from `s` to the low byte of `c`.
 *
 * @param s A writable buffer of at least `n` bytes.
 * @param c The value to set the bytes to (only the low byte will be used).
 * @param n The number of bytes to set.
 *
 * @return The buffer `s`, now set to `c`.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Zeroes the first `n` bytes from `s`.
 *
 * @param s A writable buffer of at least `n` bytes.
 * @param n The number of bytes to zero.
 *
 * @return The buffer `s`, now zeroed.
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Copies the first `n` bytes from `src` to `dest`,
 * without handling memory overlap.
 *
 * @param dest The destination buffer, a writable buffer
 * of at least `n` bytes.
 * @param src The source buffer, a buffer of at least
 * `n` bytes, which does not overlap with `dest`.
 * @param n The number of bytes to copy.
 *
 * @return The buffer `dest`, now with its first `n` bytes copied from `src`.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies the first `n` bytes from `src` to `dest`.
 *
 * @param dest The destination buffer, a writable buffer
 * of at least `n` bytes.
 * @param src The source buffer, a buffer of at least `n` bytes.
 * @param n The number of bytes to move.
 *
 * @return The buffer `dest`, now with its first `n` bytes copied from `src`.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Copies characters from `src` to `dest`, up to `dsize - 1`
 * characters. Returns the length of `src`.
 *
 * @param dest The destination string, a writable buffer of at
 * least `dsize` bytes.
 * @param src The source string, a null-terminated C string.
 * @param dsize The maximum number of characters to copy.
 *
 * @return The length of `src`.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t dsize);

/**
 * @brief Concatenates `src` to `dest` up to a total of `dsize - 1`
 * characters. Returns the length of the string it attempted to create.
 *
 * @param dest The destination string, a null-terminated C string and
 * writable buffer of at least `dsize` bytes.
 * @param src The source string, a null-terminated C string.
 * @param dsize The maximum number of characters to copy.
 *
 * @return The length of `src` plus the greater of `dsize` and the
 * length of `dest`.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t dsize);

/**
 * @brief Returns the uppercase equivalent of `c`, without locale support.
 *
 * @param c The lowercase version, an unsigned char [0, 255] or EOF (-1).
 *
 * @return The uppercase equivalent of `c` if `c` is lowercase,
 * or `c` otherwise.
 */
int		ft_toupper(int c);

/**
 * @brief Returns the lowercase equivalent of `c`, without locale support.
 *
 * @param c The uppercase version, an unsigned char [0, 255] or EOF (-1).
 *
 * @return The lowercase equivalent of `c` if `c` is uppercase,
 * or `c` otherwise.
 */
int		ft_toupper(int c);

/**
 * @brief Returns the first occurence of a character in a string.
 *
 * @param s The string to search, a null-terminated C string.
 * @param c The character to search for.
 *
 * @return A pointer to the first occurence of `c` in `s`.
 * @retval NULL – `c` was not found in `s`.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Returns the last occurence of a character in a string.
 *
 * @param s The string to search, a null-terminated C string.
 * @param c The character to search for.
 *
 * @return A pointer to the last occurence of `c` in `s`.
 * @retval NULL – `c` was not found in `s`.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Compares the first `n` characters of two strings.
 *
 * @param s1 The first string, a null-terminated C string.
 * @param s2 The second string, a null-terminated C string.
 * @param n The maximum number of characters to compare.
 *
 * @return The difference between the ASCII values of the string
 * elements at the first difference.
 * @retval 0 – The first `n` characters of the strings are equal.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Returns the first occurence of a byte in a buffer.
 *
 * @param s The buffer to search, a buffer of at least `n` bytes.
 * @param c The byte to search for.
 * @param n The maximum number of bytes to search.
 *
 * @return A pointer to the first occurence of `c` in `s`.
 * @retval NULL – `c` was not found in `s`.
 */
char	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first `n` bytes of two buffers.
 *
 * @param s1 The first buffer, a buffer of at least `n` bytes.
 * @param s2 The second buffer, a buffer of at least `n` bytes.
 * @param n The maximum number of bytes to compare.
 *
 * @return The difference of the first different byte values.
 * @retval 0 – The first `n` bytes of the buffers are equal.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Finds the first occurence of a string in another string.
 *
 * @param haystack The string to search in, a null-terminated C string.
 * @param needle The string to search for, a null-terminated C string.
 * @param n The maximum number of characters in `haystack` to search.
 *
 * @return A pointer to the first occurence of `needle` in `haystack`.
 * @retval NULL – `needle` was not found in the first `n` characters of
 * `haystack`.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

/**
 * @brief Returns the number represented by a string.
 *
 * @param nptr The string representation of the number, a
 * null-terminated C string.
 *
 * @return The number represented by `nptr`.
 * @retval 0 – `nptr` represented 0 or did not represent a number.
 * @retval `(int)LONG_MIN` – Long underflow.
 * @retval `(int)LONG_MAX` – Long overflow.
 */
int		ft_atoi(const char *nptr);

/**
 * @brief Allocates an array on the heap and initializes it to 0.
 *
 * @param nmemb The number of elements in the array.
 * @param size The size of each individual element in bytes.
 *
 * @return The new zeroed array.
 *
 * @note This function internally calls `malloc`.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Allocates and returns a duplicate of a string.
 *
 * @param s The string to copy, a null-terminated C string.
 *
 * @return The new duplicate.
 * @retval NULL – The allocation failed.
 *
 * @note This function internally calls `malloc`.
 */
char	*ft_strdup(const char *s);

#endif
