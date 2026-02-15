/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:53:19 by aalkaff           #+#    #+#             */
/*   Updated: 2026/02/15 15:18:20 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>	// NULL and size_t
# include <stdarg.h>	// va_list

/* Linked List */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ctype functions, C locale only */

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/* Returns the next power of two greater than or equal to N. */
size_t			next_power_of_two(size_t n);

/* Min and Max functions */

long			imin(long a, long b);
long			imax(long a, long b);
unsigned long	min(unsigned long a, unsigned long b);
unsigned long	max(unsigned long a, unsigned long b);

char			*get_next_line(int fd);

int				ft_printf(const char *format, ...);
int				ft_vprintf(const char *format, va_list args);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_vsprintf(char *str, const char *format, va_list args);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vdprintf(int fd, const char *format, va_list args);
int				ft_snprintf(char *str, size_t n, const char *format, ...);
int				ft_vsnprintf(char *str, size_t n, const char *format,
					va_list args);
int				ft_asprintf(char **strp, const char *format, ...);
int				ft_vasprintf(char **strp, const char *format, va_list args);

/* atoi and strtol analogues, see man pages */

int				ft_atoi(const char *nptr);
long			ft_strtol(const char *nptr, char **endptr, int base);

/* calloc and realloc analogues, see man pages. */

void			*ft_calloc(size_t nelem, size_t elsize);

/* ft_realloc requires old size because it has no access
 * to allocator internals.
 */
void			*ft_realloc(void *ptr, size_t old_size, size_t new_size);

/* libc string.h function analogues, see man pages. */

void			*ft_memset(void *ptr, int c, size_t len);
void			ft_bzero(void *ptr, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dsize);
char			*ft_strdup(const char *s);
void			*ft_memchr(const void *ptr, int c, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strnlen(const char *s, size_t n);
int				ft_memcmp(const void *p1, const void *p2, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t len);

/* Additional string functions required by libft subject.
 * Deprecated but kept for compatibility reasons. Use printf family instead.
 */

/* Deprecated. Returns the substring of S starting at START and with maximum
 * length LEN. Caller responsible for freeing.
 */
char			*ft_substr(const char *s, unsigned int start, size_t len);

/* Deprecated. Returns the substring of S1 with characters in SET.
 * Caller responsible for freeing.
 */
char			*ft_strtrim(const char *s1, const char *set);

/* Deprecated. Returns PREFIX + SUFFIX. Caller responsible for freeing. */
char			*ft_strjoin(const char *prefix, const char *suffix);

/* Returns a null terminated array of words contained in S delimited
 * by C or the ends of the string. Caller responsible for freeing.
 */
char			**ft_split(const char *s, char c);

/* Applies F to each character in S and its index. */
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

/* Applies F to each character in S and its index. Returns new string
 * with outputs. Caller responsible for freeing.
 */
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);

/* Output functions required by libft subject.
 * Deprecated but kept for compatibility reasons. Use printf family instead.
 */

/* Deprecated. Writes C to FD. */
void			ft_putchar_fd(char c, int fd);

/* Deprecated. Writes S to FD. */
void			ft_putstr_fd(char *s, int fd);

/* Deprecated. Writes S to FD, followed by a new line. */
void			ft_putendl_fd(char *s, int fd);

/* Deprecated. Writes N to FD, as a base 10 signed integer. */
void			ft_putnbr_fd(int n, int fd);

/* Linked list functions. See libft subjects. */

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *elem);
void			ft_lstadd_back(t_list **lst, t_list *elem);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
