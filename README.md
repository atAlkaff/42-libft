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

```C
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
```

#### 1.2. Converters

```C
int	ft_toupper(int c);
int	ft_tolower(int c);
```
