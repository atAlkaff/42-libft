/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:53:19 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/18 19:48:37 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>	// NULL and size_t

/**
 * @author Ahmed Alkaff
 *
 * @mainpage
 * These functions are the libft interface required by Project
 * Specification Version 18 (2025).
 */

/**
 * @defgroup ctype Character Classification and Conversion Functions
 */

/**
 * @ingroup ctype
 * @defgroup ctype_class Character Classification Functions
 * @details These functions return true if the input character
 * falls into a certain set or range. They are defined only for
 * c ∈ [0, UCHAR_MAX] or c == EOF; except for @ref ft_isascii(),
 * which is defined for all integer values. All functions here
 * are O(1) in time and space.
 */

/**
 * @ingroup ctype_class
 * @brief Returns whether @p c is alphabetical.
 * @param c The character to test, must be representable
 * as `unsigned char` or `EOF`.
 * @retval 1 @p c is alphabetical.
 * @retval 0 @p c is not alphabetical.
 */
int		ft_isalpha(int c);

/**
 * @ingroup ctype_class
 * @brief Returns whether @p c is a digit.
 * @param c The character to test, must be representable
 * as `unsigned char` or `EOF`.
 * @retval 1 @p c is a digit.
 * @retval 0 @p c is not a digit.
 */
int		ft_isdigit(int c);

/**
 * @ingroup ctype_class
 * @brief Returns whether @p c is alphanumeric.
 * @param c The character to test, must be representable
 * as `unsigned char` or `EOF`.
 * @retval 1 @p c is alphanumeric.
 * @retval 0 @p c is not alphanumeric.
 */
int		ft_isalnum(int c);

/**
 * @ingroup ctype_class
 * @brief Returns whether @p c is a printable character.
 * @param c The character to test, must be representable
 * as `unsigned char` or `EOF`.
 * @retval 1 @p c is printable.
 * @retval 0 @p c is not printable.
 */
int		ft_isprint(int c);

/**
 * @ingroup ctype_class
 * @brief Returns whether @p c is an ASCII character [0, 127].
 * @param c The character to test.
 * @retval 1 @p c is an ASCII character.
 * @retval 0 @p c is not an ASCII character.
 */
int		ft_isascii(int c);

/**
 * @ingroup ctype
 * @defgroup ctype_convert Character Conversion Functions
 * @details These functions return the upper/lowercase equivalent
 * of the input character if one exists. They are defined only for
 * c ∈ [0, UCHAR_MAX] or c == EOF. All functions here are O(1) in
 * time and space.
 */

/**
 * @ingroup ctype_convert
 * @brief Returns the uppercase equivalent of a character if one exists.
 * @param c The lowercase character, must be representable
 * as `unsigned char` or `EOF`.
 * @returns The uppercase equivalent of @p c if one exists, or
 * @p c otherwise.
 */
int		ft_toupper(int c);

/**
 * @ingroup ctype_convert
 * @brief Returns the lowercase equivalent of a character if one exists.
 * @param c The uppercase character, must be representable
 * as `unsigned char` or `EOF`.
 * @returns The lowercase equivalent of @p c if one exists, or
 * @p c otherwise.
 */
int		ft_tolower(int c);

/**
 * @defgroup string_integer String / Integer Converters
 */

/**
 * @ingroup string_integer
 * @brief Returns the number represented by a string.
 * @details The C standard requires this to have the same
 * behavior as `(int)strtol(nptr, (char **) NULL, 10)`, except
 * in so far as concerns error handling. This means that the
 * function will skip any leading whitespace, handle one optional
 * + or - sign, and then attempt to convert @p nptr into an integer.
 * If the function overflows either way, it returns the limits of
 * `long` clamped down to `int`. If @p nptr does not represent a
 * number, the function returns 0.
 * @param nptr The string representation of a number.
 * @returns The number represented by @p nptr if one existed.
 * @retval 0 @p nptr represented 0 or did not represent a number.
 * @retval `(int)LONG_MIN` @p nptr represented a negative value too
 * large to be represented as `long`.
 * @retval `(int)LONG_MAX` @p nptr represented a positive value too
 * large to be represented as `long`.
 */
int		ft_atoi(const char *nptr);

/**
 * @ingroup string_integer
 * @brief Allocates and returns a string representation of a signed integer
 * in base 10.
 * @param n The number to convert.
 * @returns On success, the function returns the string represntation
 * of @p n as a base 10 signed integer.
 *
 * On error, the functions returns NULL.
 */
char	*ft_itoa(int n);

/**
 * @defgroup malloc Memory Allocators
 * @details These functions attempt to dynamically allocate memory
 */

/**
 * @ingroup malloc
 * @brief Attempts to allocate an array of @p nelem elements of
 * size @p elsize each and set them all to 0. The function returns NULL
 * and does not attempt to allocate memory if more than PTRDIFF_MAX bytes
 * are requested.
 * @param nelem The number of elements in the array.
 * @param elsize The size of each element.
 * @returns On success, the function returns a unique pointer value that can
 * be successfully passed to `free(3)`. This is true even if 0 bytes were
 * requested; however, if 0 bytes were requested the caller must not attempt
 * to dereference the pointer.
 *
 * On error, the function returns NULL.
 */
void	*ft_calloc(size_t nelem, size_t elsize);

/**
 * @defgroup string
 * @details These functions handle strings and memory regions.
 */

/**
 * @ingroup string
 * @defgroup memset Memory Setters
 * @details These functions set a number of continguous bytes to some value.
 */

/**
 * @ingroup memset
 * @brief Sets @p len bytes of @p ptr to the low byte of @p c.
 * @param ptr The memory region.
 * @param c The byte to copy. This `int` will be cast to
 * `unsigned char`.
 * @param len The number of bytes to set.
 * @returns @p ptr
 */
void	*ft_memset(void *ptr, int c, size_t len);

/**
 * @ingroup memset
 * @brief Sets @p len bytes of @p ptr to 0.
 * @param ptr The memory region.
 * @param len The number of bytes to set.
 */
void	ft_bzero(void *ptr, size_t len);

/**
 * @ingroup string
 * @defgroup memcpy String / Memory Copiers
 * @details These functions copy bytes from one memory region to another
 */

/**
 * @ingroup memcpy
 * @brief Copies @p n bytes from @p src to @p dst
 * This function assumes the two regions do not overlap. For
 * overlapping regions, use @ref ft_memmove().
 * @param dst The destination memory region.
 * @param src The source memory region.
 * @param n The number of bytes to copy.
 * @returns @p dst
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @ingroup memcpy
 * @brief Copies @p n bytes from @p src to @p dst as if
 * an intermediate buffer was used.
 * This function safely handles overlap. For non-overlapping
 * regions, use @ref ft_memcpy() instead.
 * @param dst The destination memory region.
 * @param src The source memory region.
 * @param n The number of bytes to copy.
 * @returns @p dst
 */
void	*ft_memmove(void *dst, const void *src, size_t n);

/**
 * @ingroup memcpy
 * @brief Copies @p src to @p dst, up to @p dsize - 1 bytes.
 * @param dst The destination buffer.
 * @param src The source string.
 * @param dsize The maximum size of the destination buffer in bytes.
 * @returns The length of @p src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);

/**
 * @ingroup string
 * @defgroup strcat String Concatenators
 * @details These functions concatenate one string to another
 */

/**
 * @ingroup strcat
 * @brief Concatenates @p src to @p dst, up to a total of @p dsize - 1
 * bytes.
 * @param dst The destination string.
 * @param src The source string.
 * @param dsize The maximum total length in bytes.
 * @returns The length of @p src, plus the length of @p dst or @p dsize
 * whichever is greater.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dsize);

/**
 * @ingroup string
 * @defgroup strdup String Duplicators
 */

/**
 * @ingroup strdup
 * @brief Attempts to allocate and return a duplicate copy of @p s.
 * @param s The string to duplicate.
 * @returns The duplicate if one was created, or NULL if the allocation
 * failed.
 */
char	*ft_strdup(const char *s);

/**
 * @ingroup string
 * @defgroup strchr String / Memory Search Functions
 */

/**
 * @ingroup strchr
 * @brief Returns the first occurrence of the low byte of @p c in @p ptr.
 * @param ptr The start of the memory region to search.
 * @param c The byte to look for.
 * @param len The number of bytes to search.
 * @returns The first occurrence of the low byte of @p c in the first @p len
 * bytes starting at @p s, or NULL if the byte was not found.
 */
void	*ft_memchr(const void *ptr, int c, size_t len);

/**
 * @ingroup strchr
 * @brief Returns the first occurrence of the low byte of @p c in @p s.
 * @param s The string to search.
 * @param c The byte to look for.
 * @returns The first occurrence of the low byte of @p c in @p s,
 * or NULL if the character was not found.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @ingroup strchr
 * @brief Returns the last occurrence of the low byte of @p c in @p s
 * @param s The string to search.
 * @param c The byte to look for.
 * @returns The last occurrence of the low byte of @p c in @p s,
 * or NULL if the character was not found.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @ingroup strchr
 * @brief Returns the first occurrence of @p needle in @p haystack.
 * @param haystack The string to search in.
 * @param needle The string to search for.
 * @param n The maximum length of @p haystack to search in.
 * @returns The first occurrence of @p needle in @p haystack, or NULL
 * if it was not found.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

/**
 * @ingroup strchr
 * @brief Returns the length of a string in bytes.
 * @param s The string to search.
 * @returns The length of the string in bytes.
 */
size_t	ft_strlen(const char *s);

/**
 * @ingroup strchr
 * @brief Returns the length of a string in bytes, or @p n,
 * whichever is less.
 * @param s The string to search.
 * @param n The maximum length of the string.
 * @returns The length of the string in bytes, or @p n, whichever
 * is greater.
 */
size_t	ft_strnlen(const char *s, size_t n);

/**
 * @ingroup string
 * @defgroup strcmp String Comparator Functions
 */

/**
 * @ingroup strcmp
 * @brief Returns the difference in the first unequal bytes of the two
 * regions, or 0 if the regions have exactly the same data.
 * @param p1 The first memory region.
 * @param p2 The second memory region.
 * @param len The maximum number of bytes to compare.
 * @returns The difference in the first unequal bytes of the two
 * regions, or 0 if the regions have exactly the same data.
 */
int		ft_memcmp(const void *p1, const void *p2, size_t len);

/**
 * @ingroup strcmp
 * @brief Returns the difference in the first unequal characters of
 * the strings.
 * @param s1 The first string.
 * @param s2 The second string.
 * @param len The maximum number of bytes to compare.
 * @returns The difference in the first unequal characters, or
 * 0 if the strings are equal.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t len);

/**
 * @defgroup stringx 42 String Extensions
 * @details These functions are required by libft project specification
 * but not by any version of the libc specification.
 */

/**
 * @ingroup stringx
 * @defgroup substr Substring Functions
 */

/**
 * @ingroup substr
 * @brief Attempts to allocate and return a substring of @p s
 * @param s The original string.
 * @param start The index at which the substring starts.
 * @param len The maximum length of the substring.
 * @returns On success, the function returns the substring.
 *
 * On error, the function returns NULL.
 */
char	*ft_substr(const char *s, unsigned int start, size_t len);

/**
 * @ingroup substr
 * @brief Attempts to allocate and return a substring of @p s1 where
 * characters in @p set are trimmed from both ends.
 * @param s1 The original string.
 * @param set A set of characters to trim.
 * @returns On success, the function returns the trimmed string.
 *
 * On error, the function returns NULL.
 */
char	*ft_strtrim(const char *s1, const char *set);

/**
 * @ingroup stringx
 * @defgroup strjoinsplit String Joiners / Splitters
 */

/**
 * @ingroup strjoinsplit
 * @brief Attempts to allocate and return a string containing
 * @p suffix concatenated to @p prefix.
 * @param prefix The first string.
 * @param suffix The second string.
 * @returns On success, the function returns the joined string.
 *
 * On error, the function returns NULL.
 */
char	*ft_strjoin(const char *prefix, const char *suffix);

/**
 * @ingroup strjoinsplit
 * @brief Attempts to allocate and return a null-terminated array
 * of strings made @p s and separated by @p c.
 * @param s The string to split.
 * @param c The delimiter character.
 * @returns On success, the function returns a null-terminated array
 * of strings in @p s delimited by @p c and the end of the string.
 *
 * On error, the function returns NULL.
 */
char	**ft_split(const char *s, char c);

/**
 * @ingroup stringx
 * @defgroup striteri String Iterators / Mappers
 */

/**
 * @ingroup striteri
 * @brief Applies @p f to every character in @p s and its
 * index, allowing @p f to modify their values.
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @ingroup striteri
 * @brief Attempts to allocate and return a string with its characters
 * having values returned by @p f to each character in @p s and its index.
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 * @returns On success, the function returns the new string.
 *
 * On error, the function returns NULL.
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/**
 * @defgroup io Input / Output Functions
 */

/**
 * @ingroup io
 * @defgroup output Output Functions
 * @details These functions write data to a file descriptor.
 */

/**
 * @ingroup output
 * @brief Writes @p c to @p fd.
 * @param c The character to write.
 * @param fd The file descriptor to write to.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @ingroup output
 * @brief Writes @p s to @p fd.
 * @param s The string to write.
 * @param fd The file descriptor to write to.
 * @note @p s is not const-qualified because this prototype is required
 * by specification. The caller may assume this function does not modify
 * @p s and treat that parameter as if it were of type `const char *`.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @ingroup output
 * @brief Writes @p s to @p fd, followed by a newline.
 * @param s The string to write.
 * @param fd The file descriptor to write to.
 * @note @p s is not const-qualified because this prototype is required
 * by specification. The caller may assume this function does not modify
 * @p s and treat that parameter as if it were of type `const char *`.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @ingroup output
 * @brief Writes @p n to @p fd represented as a base 10
 * signed integer.
 * @param n The number to write.
 * @param fd The file descriptor to write to.
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * @ingroup output
 * @brief Prints a formatted string to stdout.
 * @param format The format string. All additional parameters
 * are meant to replace conversion specifiers starting with "%".
 * @returns On success, the function returns the number of
 * bytes actually written.
 *
 * On error, the function returns -1.
 */
int		ft_printf(const char *format, ...);

/**
 * @defgroup list Linked List Functions
 */

/**
 * @ingroup list
 * @brief A type-independent non-circular linked list structure.
 */
typedef struct s_list
{
	/**
	 * @brief A pointer to the content of the list node.
	 */
	void			*content;
	/**
	 * @brief A pointer to the next node. If this is NULL, then
	 * the current node is the last node in the list.
	 */
	struct s_list	*next;
}	t_list;

/**
 * @ingroup list
 * @brief Attempts to allocate and return a new list node.
 * @param content The content of the node.
 * @returns On success, the function returns the new node.
 *
 * On error, the function returns NULL.
 */
t_list	*ft_lstnew(void *content);

/**
 * @ingroup list
 * @brief Adds a node to the start of @p lst.
 * @param lst A pointer to the start of the list.
 * @param elem The new node.
 */
void	ft_lstadd_front(t_list **lst, t_list *elem);

/**
 * @ingroup list
 * @brief Adds a node to the end of @p lst.
 * @param lst A pointer to the start of the list.
 * @param elem The new node.
 */
void	ft_lstadd_back(t_list **lst, t_list *elem);

/**
 * @ingroup list
 * @brief Returns the length of @p lst.
 * @param lst The start of the list.
 * @returns The number of nodes in the list starting
 * at @p lst.
 */
int		ft_lstsize(t_list *lst);

/**
 * @ingroup list
 * @brief Returns the last node of @p lst.
 * @param lst The start of the list.
 * @returns The last node in the list starting
 * at @p lst.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @ingroup list
 * @brief Frees a list node.
 * @param lst The node to free.
 * @param del A function that frees the content of the node.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @ingroup list
 * @brief Frees the whole list starting at @p lst and set @p lst to NULL.
 * @param lst A pointer to the start of the list.
 * @param del A function that frees the content of a node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @ingroup list
 * @brief Iterates over a list and applies a function to each node.
 * @param lst The start of the list.
 * @param f The function to be applied.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @ingroup list
 * @brief Attempts to allocate and return a new list containing the
 * contents of @p lst after @p f is applied to them.
 * @param lst The start of the list.
 * @param f The function to be applied.
 * @param del A function that frees the content of a node if needed.
 * @returns On success, the function returns the new list.
 *
 * On error, the function returns NULL.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
