/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:47:55 by aalkaff           #+#    #+#             */
/*   Updated: 2025/08/22 21:39:06 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

// size_t and NULL
# include <stddef.h>

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
 * @post If `ft_strlen(dest) >= n`, then `dest` is unchanged.
 * Otherwise, `src` is concatenated up to a total length of `n - 1`
 * and `dest` is null terminated.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t n);

/**
 * @defgroup strdup String Duplication Functions
 * @ingroup string
 * @details These functions allocate on the heap a deep copy of
 * the string they receive as input and return that deep copy.
 */

/**
 * @ingroup strdup
 * @brief Allocates and returns a deep copy of `s`.
 *
 * @param s The string to duplicate.
 *
 * @return A pointer to deep copy of `s`.
 * @retval NULL – The allocation failed.
 */
char	*ft_strdup(const char *s);

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

/**
 * @ingroup string_search
 * @brief Finds the first occurrence of a the least significant
 * byte of `c` in a memory region.
 *
 * @param s The buffer to search.
 * @param c The byte to search for.
 * @param n The number of bytes to search.
 *
 * @return A pointer to the first occurrence of `(unsigned char) c`
 * in the first `n` bytes of `s`.
 * @retval NULL – `(unsigned char) c` was not found in the first
 * `n` bytes of `s`.
 *
 * @pre `s` points to at least `n` bytes of memory.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @ingroup string_search
 * @brief Finds the first occurrence of a the least significant
 * byte of `c` in a string.
 *
 * @param s The string to search.
 * @param c The byte to search for.
 *
 * @return A pointer to the first occurrence of `(unsigned char) c`
 * in `s`.
 * @retval NULL – `(unsigned char) c` was not found in `s`.
 *
 * @pre `s` points to a string.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @ingroup string_search
 * @brief Finds the last occurrence of a the least significant
 * byte of `c` in a string.
 *
 * @param s The string to search.
 * @param c The byte to search for.
 *
 * @return A pointer to the last occurrence of `(unsigned char) c`
 * in `s`.
 * @retval NULL – `(unsigned char) c` was not found in `s`.
 *
 * @pre `s` points to a string.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @ingroup string_search
 * @brief Finds the first occurrence of substring `needle` in
 * the first `min(n, ft_strlen(haystack))` bytes of `haystack`.
 *
 * @param haystack The string to search in.
 * @param needle The string to search for.
 * @param n The maximum number of bytes to search.
 *
 * @return A pointer to the first occurrence of `needle` in
 * the first `min(n, ft_strlen(haystack))` bytes of `haystack`.
 * @retval NULL – `needle` was not found in the first
 * `min(n, ft_strlen(haystack))` bytes of `haystack`.
 *
 * @pre `haystack` and `needle` point to strings.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

/**
 * @defgroup substr Substring Function
 * @ingroup string
 * @details These functions allocate on the heap a substring of their
 * input and return that substring.
 */

/**
 * @ingroup substr
 * @brief Allocates and returns a substring of `s` starting at
 * index `start` up to `len` characters long.
 *
 * @param s The original string.
 * @param start The starting index of the substring.
 * @param len The maximum length of the substring.
 *
 * @return A pointer to the new substring.
 * @retval NULL – The allocation failed.
 *
 * @pre `s` points to a string.
 *
 * @note If `start + len > ft_strlen(s)`, then the substring's length
 * is capped at `ft_strlen(s) - start` or 0, whichever is greater.
 */
char	*ft_substr(const char *s, unsigned int start, size_t len);

/**
 * @ingroup substr
 * @brief Allocates and returns a substring of `s1`, trimmed by
 * removing all leading and trailing characters in `set`.
 *
 * @param s1 The original string.
 * @param set The set of characters to remove from the start
 * and end of `s1`.
 *
 * @return A pointer to the trimmed string.
 * @retval NULL – The allocation failed.
 *
 * @pre `s1` and `set` point to strings.
 */
char	*ft_strtrim(const char *s1, const char *set);

/**
 * @defgroup strjoinsplit String Join / Split
 * @ingroup string
 * @details These functions join or split strings they receive
 * as input and return pointers to heap-allocated strings or
 * arrays.
 */

/**
 * @ingroup strjoinsplit
 * @brief Allocates and returns a string that is the result
 * of concatenating `s1` and `s2`.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 *
 * @return A pointer to the joined string.
 * @retval NULL – The allocation failed.
 *
 * @pre `s1` and `s2` point to strings.
 */
char	*ft_strjoin(const char *s1, const char *s2);

/**
 * @ingroup strjoinsplit
 * @brief Allocates and returns a null-terminated array of
 * words in `s` separated by any number of contiguous `c` characters.
 *
 * @return A pointer to the null-terminated array of strings.
 * @retval NULL – The allocation failed.
 *
 * @pre `s` points to a string.
 * @note This function does not return the size of the array. Instead,
 * it appends a `NULL` element at the end to signify that there are no
 * more strings.
 */
char	**ft_split(const char *s, char c);

/**
 * @defgroup stritmap String Iterators and Mappers
 * @ingroup string
 * @details These functions call a function on all characters
 * of a string.
 */

/**
 * @ingroup stritmap
 * @brief Calls `f` on all characters in `s` and their indices,
 * allowing `f` to change the values of the characters.
 *
 * @param s The string to iterate over.
 * @param f The function to call on each character and index.
 *
 * @pre `s` points to a writable buffer that contains a string.
 * @pre `f` points to a function that accepts an unsigned integer
 * (the index) and a character pointer (to allow change).
 * @warning If `f` fails to handle valid input, the behavior is
 * undefined.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @ingroup stritmap
 * @brief Allocates and returns a string whose characters are the
 * result of `f(i, s[i])` for each character in `s`.
 *
 * @param s The string to iterate over.
 * @param f The function to call on each character and index.
 *
 * @return A pointer to the new string.
 * @retval NULL – The allocation failed.
 *
 * @pre `s` points to a writable buffer that contains a string.
 * @pre `f` points to a function that accepts an unsigned integer
 * (the index) and a character.
 * @warning If `f` fails to handle valid input, the behavior is
 * undefined.
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/**
 * @defgroup intstr Integer / String Converters
 * @details These functions convert between a number and its string
 * representation.
 */

/**
 * @ingroup intstr
 * @brief Returns the number represented by `nptr`. The function
 * skips leading whitespace and handles one optional + or - sign,
 * then reads until the first non-digit character.
 *
 * @param nptr The string representation of a number.
 *
 * @return The number represented by `nptr`.
 *
 * @retval 0 – `nptr` represented 0 or did not begin with a digit.
 * @retval (int)LONG_MIN – `nptr` represented `(int)LONG_MIN` or
 * a number less than `LONG_MIN`.
 * @retval (int)LONG_MAX – `nptr` represented `(int)LONG_MAX` or
 * a number greater than `LONG_MAX`.
 *
 * @pre `nptr` points to a string.
 */
int		ft_atoi(const char *nptr);

/**
 * @ingroup intstr
 * @brief Allocates and returns the string representation
 * of `n`.
 *
 * @param n The number to be converted.
 *
 * @return A pointer to a string representing `n`.
 * @retval NULL – The allocation failed.
 */
char	*ft_itoa(int n);

/**
 * @defgroup io Input / Output Functions
 * @details These functions are system call wrappers that
 * read from or write to a file descriptor. See POSIX.1-2008
 * Section 3.165 ("File Descriptor").
 */

/**
 * @ingroup io
 * @brief Writes `c` to `fd`.
 *
 * @param c The character to write.
 * @param fd The file descriptor.
 *
 * @pre The caller has permission to write to `fd`.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @ingroup io
 * @brief Writes `s` to `fd`.
 *
 * @param s The string to write.
 * @param fd The file descriptor.
 *
 * @pre `s` points to a string.
 * @pre The caller has permission to write to `fd`.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @ingroup io
 * @brief Writes `s` to `fd`, followed by a newline.
 *
 * @param s The string to write.
 * @param fd The file descriptor.
 *
 * @pre `s` points to a string.
 * @pre The caller has permission to write to `fd`.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @ingroup io
 * @brief Writes the string representation of `n` to `fd`.
 *
 * @param n The number to write.
 * @param fd The file descriptor.
 *
 * @pre The caller has permission to write to `fd`.
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * @defgroup linkedlist Linked Lists
 * @details The linked list structure (`s_list`) and its
 * member functions.
 */

/**
 * @ingroup linkedlist
 * @brief Linked list node.
 */
typedef struct s_list
{
	/**
	 * @brief The data contained by the node. This may be `NULL`.
	 */
	void			*content;
	/**
	 * @brief A pointer to the next node in the list.
	 * If this is `NULL`, the current node is the last node.
	 */
	struct s_list	*next;
}	t_list;

/**
 * @defgroup linkedlist_constructor Constructors
 * @ingroup linkedlist
 * @details These functions allocate and return linked list
 * nodes.
 */

/**
 * @ingroup linkedlist_constructor
 * @memberof s_list
 * @brief Allocates and returns a new linked list node. The node
 * will have `content` as its content and `next` set to `NULL`.
 *
 * @param content A pointer to the node's content.
 *
 * @return A pointer to the new list node.
 * @retval NULL – The allocation failed.
 */
t_list	*ft_lstnew(void *content);

/**
 * @defgroup linkedlist_add Append Functions
 * @ingroup linkedlist
 * @details These functions append a new element to a
 * linked list.
 */

/**
 * @ingroup linkedlist_add
 * @memberof s_list
 * @brief Adds `element` to the start of `lst`.
 *
 * @param lst A pointer to the address of the first element.
 * If this is `NULL`, the list is empty.
 * @param element The new element.
 *
 * @pre `lst` points to a list pointer or `NULL`.
 * @pre `element` is a valid list pointer.
 * @post `*lst == element`
 */
void	ft_lstadd_front(t_list **lst, t_list *element);

/**
 * @ingroup linkedlist_add
 * @memberof s_list
 * @brief Adds `element` to the end of `lst`.
 *
 * @param lst A pointer to the address of the first element.
 * If this is `NULL`, the list is empty.
 * @param element The new element.
 *
 * @pre `lst` points to a list pointer or `NULL`.
 * @pre `element` is a valid list pointer.
 * @post `ft_lstlast(*lst) == element`
 */
void	ft_lstadd_back(t_list **lst, t_list *element);

/**
 * @defgroup linkedlist_iter Iterators
 * @ingroup linkedlist
 * @details These functions simply iterate over list elements
 * until reaching `NULL`. They do not call external functions.
 */

/**
 * @ingroup linkedlist_iter
 * @memberof s_list
 * @brief Returns the last element of `lst`.
 *
 * @param lst A pointer to the first element in the list.
 *
 * @return A pointer to the last element.
 *
 * @pre `lst` is a valid list pointer.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @ingroup linkedlist_iter
 * @memberof s_list
 * @brief Returns the number of nodes starting from `lst`
 * until and excluding `NULL`.
 *
 * @param lst A pointer to the first element in the list.
 *
 * @return The number of elements in `lst`.
 *
 * @pre `lst` is a valid list pointer.
 */
int		ft_lstsize(t_list *lst);

/**
 * @defgroup linkedlist_funciter Functional Iterators and Mappers
 * @ingroup linkedlist
 * @details These functions iterate over all elements in a list
 * and call a given function on each one's content.
 */

/**
 * @ingroup linkedlist_funciter
 * @memberof s_list
 * @brief Applies `f` to the content of every element in `lst`. `f`
 * may manipulate the content of any node.
 *
 * @param lst A pointer to the first element in the list.
 * @param f The function to call on each element's content.
 *
 * @pre `lst` is a valid list pointer.
 * @pre `f` is a valid pointer to a function that takes a pointer
 * argument and returns nothing.
 *
 * @warning The content of a node may validly be `NULL`. Therefore,
 * `f` is required to safely handle `NULL`. If `f` fails to handle
 * valid input, the behavior is undefined.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @ingroup linkedlist_funciter
 * @memberof s_list
 * @brief Allocates and returns a list whose elements have
 * `f(lst->content)` as their content. If one allocation fails,
 * the function frees the new list and returns `NULL`.
 *
 * @param lst A pointer to the first element in the list.
 * @param f The function to call on each element's content.
 * @param del A function that frees the content of an element.
 *
 * @return A pointer to the new list.
 * @retval NULL – The allocation failed.
 *
 * @pre `lst` is a valid list pointer.
 * @pre `f` is a valid pointer to a function that takes a pointer
 * argument and returns nothing.
 *
 * @warning The content of a node may validly be `NULL`. Therefore,
 * `f` is required to safely handle `NULL`. If `f` fails to handle
 * valid input, the behavior is undefined.
 * @warning `del` must properly free the content of a list element.
 * If `del` fails to completely free the content and any pointers
 * that become unusable upon freeing it, this function leaks memory.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @defgroup linkedlist_delete Destructors
 * @ingroup linkedlist
 * @details These functions free a linked list or one of its nodes
 * and the content of all freed nodes.
 */

/**
 * @ingroup linkedlist_delete
 * @memberof s_list
 * @brief Frees `lst` (but not the next node) and frees its
 * content using `del`.
 *
 * @param lst A pointer to the node to be freed.
 * @param del The function that frees the content.
 *
 * @pre `lst` is a valid list pointer.
 *
 * @warning `del` must properly free the content of a list element.
 * If `del` fails to completely free the content and any pointers
 * that become unusable upon freeing it, this function leaks memory.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @ingroup linkedlist_delete
 * @memberof s_list
 * @brief Frees all nodes starting at `*lst` and frees their contents
 * using `del`, then sets `*lst` to `NULL`. If `*lst` is `NULL`, the
 * function does nothing.
 *
 * @param lst A pointer to the address of the first node.
 * @param del The function that frees the content of a node.
 *
 * @pre `lst` points to a valid list pointer or `NULL`.
 *
 * @post `*lst == NULL`
 *
 * @warning `del` must properly free the content of a list element.
 * If `del` fails to completely free the content and any pointers
 * that become unusable upon freeing it, this function leaks memory.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

#endif
