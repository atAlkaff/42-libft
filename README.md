# 42-libft

## Part 1 Functions

### 1. ctype functions

All ctype functions run on the default C locale (POSIX), regardless
of what the current machine locale is.

All ctype functions are defined only for values representable as
`unsigned char` (that is, [0, 255]) and for `EOF` (-1).

All ctype functions are O(1) pure functions with no side effects.

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
