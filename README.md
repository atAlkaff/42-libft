# 42-libft

## Functions

All character and string functions run on the default C locale
(POSIX), regardless of what the current machine locale is.

All pointer arguments must be valid pointers. All string arguments
must be null-terminated C strings.

### 1. ctype functions

All ctype functions are defined only for values representable as
`unsigned char` (that is, [0, 255]) and for `EOF` (-1).

All ctype functions are O(1) pure functions.

All ctype functions are thread-safe.

#### 1.1. Checkers

These functions return 1 if `c` is a member of the function's target
group (e.g. digits for `ft_isdigit`) or 0 otherwise.

```C
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
```

#### 1.2. Converters

These functions return the upper/lowercase equivalent of `c` if one
exists, or `c` otherwise.

```C
int	ft_toupper(int c);
int	ft_tolower(int c);
```

### 2. stdlib functions

#### 2.1. Memory Allocators

```C
void	*ft_calloc(size_t nmemb, size_t size);
```

This function allocates and returns a heap-allocated array of `nmemb`
elements of size `size` each. The entire memory chunk is zeroed.

This function internally calls `malloc()`. If `malloc` fails, this
function returns `NULL`.

If `nmemb * size` is 0, the function returns a unique pointer that can
be successfully passed to `free()`.

If `nmemb * size` is greater than `SIZE_MAX`, this function returns
`NULL`.

This function is O(1) in most cases, but may be O(log n) or O(n) in
the worst case depending on how `malloc` is implemented on the user's
machine.

This function is thread-safe.

#### 2.2. Integer/String Converters

```C
int	ft_atoi(const char *nptr);
```

This function returns the number represented by `nptr`. The function
skips leading whitespace characters and handles one optional + or -
sign, then reads until it reaches the first non-digit character.

If `nptr` is not a number, this function returns 0.

If `nptr` represents a number greater than `LONG_MAX`, the function
returns `(int)LONG_MAX`. If `nptr` represents a number less than
`LONG_MIN`, the function returns `(int)LONG_MIN`.

This function is O(n) and pure.

This function is thread-safe.

```C
char	*ft_itoa(int n)
```

This function returns the string representation of `n`.

This function internally calls `malloc()`. If `malloc` fails, this
function returns `NULL`.

This function is O(n).

This function is thread-safe.
