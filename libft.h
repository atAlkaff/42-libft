/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:47:55 by aalkaff           #+#    #+#             */
/*   Updated: 2025/08/22 19:29:06 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

// size_t and NULL
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @mainpage
 *
 * ## Caller Responsibility
 * For all libft functions, the caller is responsible for passing
 * valid input. If any libft function is called with invalid input
 * (such as a value outside the function's domain, a pointer to
 * invalid memory, a null pointer unless otherwise specified, a
 * buffer that is too small, or a pointer to non-modifiable storage
 * when the corresponding parameter is not const qualified), the
 * behavior is undefined. This mirrors other implementations of
 * libc and adjacent libraries. See ISO 9899:1999 ("C99 Standard")
 * Section 7.1.4 ("Use of library functions").
 *
 * ## Definitions
 * - A "byte" is 8 bits. See POSIX.1-2008 Section 3.83.
 * - A "string" is a null-terminated character array (a "C string").
 * See C99 Standard Section 7.1.1 ("Definitions of terms").
 *
 * ## Locale
 * Libft functions do not support locales. All libft functions run on
 * the default "C locale" or "POSIX locale" regardless of what the
 * current machine locale is.
 */

/**
 * @defgroup ctype Character Classification and Conversion functions
 */

/**
 * @defgroup ctype_class Classification Functions
 * @ingroup ctype
 */

/**
 * @ingroup ctype_class
 * @brief Checks if a character is alphabetical.
 *
 * @param c The character to test.
 *
 * @retval 1 – `c` is alphabetical.
 * @retval 0 – `c` is not alphabetical.
 *
 * @pre `c` is a value representable as `unsigned char` or `EOF`,
 * that is, @f$ c \in [-1, 255] @f$.
 */
int		ft_isalpha(int c);

/**
 * @ingroup ctype_class
 * @brief Checks if a character is a digit.
 *
 * @param c The character to test.
 *
 * @retval 1 – `c` is a digit.
 * @retval 0 – `c` is not a digit.
 *
 * @pre `c` is a value representable as `unsigned char` or `EOF`,
 * that is, @f$ c \in [-1, 255] @f$.
 */
int		ft_isdigit(int c);

/**
 * @ingroup ctype_class
 * @brief Checks if a character is alphanumeric.
 *
 * @param c The character to test.
 *
 * @retval 1 – `c` is alphanumeric.
 * @retval 0 – `c` is not alphanumeric.
 *
 * @pre `c` is a value representable as `unsigned char` or `EOF`,
 * that is, @f$ c \in [-1, 255] @f$.
 */
int		ft_isalnum(int c);

/**
 * @ingroup ctype_class
 * @brief Checks if a character is a member of the ASCII
 * character set [0, 127].
 *
 * @param c The character to test.
 *
 * @retval 1 – `c` is ASCII.
 * @retval 0 – `c` is not ASCII.
 *
 * @pre `c` is a value representable as `unsigned char` or `EOF`,
 * that is, @f$ c \in [-1, 255] @f$.
 */
int		ft_isascii(int c);

/**
 * @ingroup ctype_class
 * @brief Checks if a character is a printable character.
 *
 * @param c The character to test.
 *
 * @retval 1 – `c` is printable.
 * @retval 0 – `c` is not printable.
 *
 * @pre `c` is a value representable as `unsigned char` or `EOF`,
 * that is, @f$ c \in [-1, 255] @f$.
 */
int		ft_isprint(int c);

/**
 * @defgroup ctype_convert Conversion Functions
 * @ingroup ctype
 */

/**
 * @ingroup ctype_convert
 * @brief Converts a character to uppercase.
 *
 * @param c The character to convert.
 *
 * @return The uppercase equivalent of `c` if one exists, or
 * `c` otherwise.
 *
 * @pre `c` is a value representable as `unsigned char` or `EOF`,
 * that is, @f$ c \in [-1, 255] @f$.
 */
int		ft_toupper(int c);

/**
 * @ingroup ctype_convert
 * @brief Converts a character to lowercase.
 *
 * @param c The character to convert.
 *
 * @return The lowercase equivalent of `c` if one exists, or
 * `c` otherwise.
 *
 * @pre `c` is a value representable as `unsigned char` or `EOF`,
 * that is, @f$ c \in [-1, 255] @f$.
 */
int		ft_tolower(int c);

/**
 * @defgroup memalloc Memory Allocators
 *
 * @details These functions attempt to allocate a chunk of memory.
 * If the caller requests more than `PTRDIFF_MAX` bytes, these
 * functions fail. This is because chunks larger than that overflow
 * the signed integer type `ptrdiff_t` on addition and is language
 * undefined behavior. See C99 Standard Section 7.17 ("Common
 * Definitions <stddef.h>"); Section 3.4.3 ("Undefined Behavior"),
 * example paragraph.
 */

/**
 * @ingroup memalloc
 *
 * @brief Attempts to allocate an array on the heap and
 * initialize all its elements to 0.
 *
 * @param nmemb The number of elements in the array.
 * @param size The size (in bytes) of each element.
 *
 * @return A pointer to the start of the array. \n
 * If `nmemb` or `size` is 0, the function returns a unique
 * pointer that may successfully be passed to `free()`. The
 * caller must not attempt to dereference that pointer. See C99
 * Standard Section 7.20.3 ("Memory management functions").
 *
 * @retval NULL – The allocation failed (insufficient memory or
 * attempt to allocate more than `PTRDIFF_MAX` bytes).
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @defgroup string String / Memory Functions
 */

/**
 * @defgroup string_size Size / Length Functions
 * @ingroup string
 * @details These functions return the length of a string,
 * which is defined as the number of bytes in the string, excluding
 * the null terminating byte.
 */

/**
 * @ingroup string_size
 * @brief Calculates the length of a string.
 *
 * @param s The string to read.
 *
 * @return The length of `s`.
 *
 * @pre `s` points to a string.
 */
size_t	ft_strlen(const char *s);

/**
 * @defgroup memset Memory Setter Functions
 * @ingroup string
 * @details These functions set all bytes in a memory region to
 * some fixed value.
 */

/**
 * @ingroup memset
 * @brief Sets the first `n` bytes of `dest` to the least
 * significant byte of `c`.
 *
 * @param dest The destination buffer.
 * @param c The byte to copy.
 * @param n The number of bytes to set.
 *
 * @return `dest`
 *
 * @pre `dest` points to at least `n` bytes of writable memory.
 * @post The first `n` bytes of `dest` are `(unsigned char) c`.
 */
void	*ft_memset(void *dest, int c, size_t n);

/**
 * @ingroup memset
 * @brief Sets the first `n` bytes of `dest` to 0.
 *
 * @param dest The destination buffer.
 * @param n The number of bytes to set.
 *
 * @pre `dest` points to at least `n` bytes of writable memory.
 * @post The first `n` bytes of `dest` are 0.
 */
void	ft_bzero(void *dest, size_t n);

/**
 * @defgroup copiers Copy Functions
 * @ingroup string
 * @details These functions copy one string or memory region to
 * another. The `dest` parameter to each of these functions is
 * a writable buffer. The fact that it may be declared `char *`
 * does not require the caller to pass a string. Instead, it
 * guarantees that after a successful function call, the buffer
 * will contain a string.
 */

/**
 * @ingroup copiers
 * @brief Copies `n` bytes from `src` to `dest`. If `src` and `dest`
 * overlap, use @ref ft_memmove() instead.
 *
 * @param dest The destination buffer.
 * @param src The source buffer.
 * @param n The number of bytes to copy.
 *
 * @return `dest`
 *
 * @pre `dest` points to at least `n` bytes of writable memory.
 * @pre `src` points to at least `n` bytes of memory.
 * @post The first `n` bytes of `dest` have the same values as
 * the first `n` bytes of `src`.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @ingroup copiers
 * @brief Copies `n` bytes from `src` to `dest` as if an intermediate
 * buffer was used. This function safely handles overlapping memory
 * regions. If there is no overlap, use @ref ft_memcpy() instead.
 *
 * @param dest The destination buffer.
 * @param src The source buffer.
 * @param n The number of bytes to copy.
 *
 * @return `dest`
 *
 * @pre `dest` points to at least `n` bytes of writable memory.
 * @pre `src` points to at least `n` bytes of memory.
 * @post The first `n` bytes of `dest` have the same values that
 * the first `n` bytes of `src` had before the function call.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @ingroup copiers
 * @brief Copies characters from `src` to `dest` until a null
 * terminating character is found or until `n - 1` characters
 * are copied.
 *
 * @param dest The destination buffer.
 * @param src The source string.
 * @param n The maximum size of the resulting string.
 * @return The length of `src`.
 *
 * @pre `dest` points to at least `min(n, ft_strlen(src) + 1)`
 * bytes of writable memory.
 * @pre `src` points to a string.
 * @post The first `min(n - 1, ft_strlen(src))` bytes of `dest` are
 * the same as `src`. The next byte in `dest` is the null terminator.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t n);

/**
 * @defgroup concat Concatenation Functions
 * @ingroup string
 * @details These functions concatenate one string to another.
 * The `dest` parameter to each of these functions is a writable
 * buffer which must contain a string.
 */

/**
 * @ingroup concat
 * @brief Concatenates `src` to `dest` up to a total of `n - 1`
 * bytes.
 *
 * @param dest The destination string.
 * @param src The source string.
 * @param n The maximum size of the resulting string.
 *
 * @return `ft_strlen(src) + min(ft_strlen(dest), n)`
 *
 * @pre `dest` points to a writable string.
 * @pre `src` points to a string.
 * @post If `dest` was longer than `n - 1`, the next bytes have
 * the same values as `src`, up to a total of `n - 1` bytes.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t n);

/**
 * @defgroup comparators Comparison Functions
 * @ingroup string
 * @details These functions compare two strings or memory regions
 * up to a number of bytes, then return the difference of the first
 * two different bytes casted to `unsigned char`. If no difference
 * is found, these functions return 0.
 */

/**
 * @ingroup comparators
 * @brief Compares the first `n` bytes of two memory regions.
 *
 * @param s1 The first region.
 * @param s2 The second region.
 * @param n The maximum number of bytes to compare.
 *
 * @return The difference in the values of the first two different
 * bytes, each casted to `unsigned char`.
 * @retval 0 – The first `n` bytes of the two regions all have
 * the same values.
 *
 * @pre `s1` and `s2` each point to at least `n` bytes of memory.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @ingroup comparators
 * @brief Compares two strings, until a null terminator is reached
 * or until `n` bytes are read, whichever is earlier.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n The maximum number of bytes to compare.
 *
 * @return The difference in the values of the first two different
 * bytes, each casted to `unsigned char`.
 * @retval 0 – `s1` and `s2` have the exact same characters or the
 * first `n` bytes have the same values.
 *
 * @pre `s1` and `s2` point to strings.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @defgroup string_search String Search Functions
 * @ingroup string
 * @details These functions search for a character or a string in
 * a string or memory region.
 */

void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

// Duplicators

char	*ft_strdup(const char *s);

// Substring Functions

char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strtrim(const char *s1, const char *set);

// Join/Split Functions

char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(const char *s, char c);

// String Iterators

void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

// Integer/String Converters

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

// Input/Output Functions

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Linked List Functions

// Constructor

t_list	*ft_lstnew(void *content);

// Appenders

void	ft_lstadd_front(t_list **lst, t_list *element);
void	ft_lstadd_back(t_list **lst, t_list *element);

// Searchers

t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

// Iterators

void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Deleters

void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));

#endif
