/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:47:55 by aalkaff           #+#    #+#             */
/*   Updated: 2025/08/21 22:43:33 by aalkaff          ###   ########.fr       */
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
 * ## Definition of string
 * For all libft purposes, a "string" is a null-terminated character
 * array (a "C string"). See C99 Standard Section 7.1.1 ("Definitions
 * of terms").
 *
 * ## Locale
 * Libft functions do not support locales. All libft functions run on
 * the default "C locale" or "POSIX locale" regardless of what the
 * current machine locale is.
 */

/**
 * @defgroup ctype Character classification and conversion functions
 */

/**
 * @defgroup ctype_class Classification functions
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
 * @defgroup ctype_convert Conversion functions
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

// Memory Allocators

void	*ft_calloc(size_t nmemb, size_t size);

// String Functions

// Memory Setters

void	*ft_memset(void *dest, int c, size_t n);
void	ft_bzero(void *dest, size_t n);

// Copiers

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);

// Concatenators

size_t	ft_strlcat(char *dest, const char *src, size_t n);

// Comparators

int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// Searchers

void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
size_t	ft_strlen(const char *s);

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
