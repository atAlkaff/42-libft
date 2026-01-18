/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:03:35 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/18 19:47:33 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

/**
 * @defgroup printf_flags Printf Flags
 */

/**
 * @ingroup printf_flags
 * @brief Justifies content to the left if the conversion
 * length is less than the minimum width.
 */
# define FMT_LEFT_JUSTIFY 1

/**
 * @ingroup printf_flags
 * @brief Pads integer conversions with zeros on the left
 * unless left justify is specified.
 */
# define FMT_ZERO_PAD 2

/**
 * @ingroup printf_flags
 * @brief Enables precision.
 */
# define FMT_PRECISION_ON 4

/**
 * @ingroup printf_flags
 * @brief Adds a space before positive signed numbers.
 */
# define FMT_PLUS_SIGN_SPACE 8

/**
 * @ingroup printf_flags
 * @brief Always shows + signs before positive signed numbers.
 */
# define FMT_PLUS_SIGN_SHOW 16

/**
 * @ingroup printf_flags
 * @brief Adds "0x" before hexadecimal conversions.
 */
# define FMT_ALT_FORM 32

/**
 * @brief A printf format specifier.
 */
typedef struct s_format
{
	/**
	 * @brief The precision. For s conversions, this is the
	 * maximum number of characters from the string. For d, i,
	 * u, x, and X conversions, this is the minimum number of
	 * digits. Zeros will be added to the left until the precision
	 * is reached. If @ref FMT_PRECISION_ON is disabled, this field
	 * is ignored.
	 */
	size_t			precision;
	/**
	 * @brief The minimum width. If the total length of the conversion
	 * comes out to a number smaller than this, padding will be added
	 * in accordance with @ref FMT_ZERO_PAD
	 */
	size_t			width;
	/**
	 * @brief The format specifier character: one of c, s, p, d, i,
	 * u, x, X, and %.
	 */
	unsigned char	specifier;
	/**
	 * @brief A set of bit fields representing a combination
	 * of the flags "-0.# +". They are represented as follows:
	 *
	 * bit 0:	Flag '-', use @ref FMT_LEFT_JUSTIFY. This flag applies to all
	 * conversions and overrides @ref FMT_ZERO_PAD.
	 *
	 * bit 1:	Flag '0', use @ref FMT_ZERO_PAD. This flag applies to d, i,
	 * u, x, and X conversions. If @ref FMT_LEFT_JUSTIFY is set, this
	 * flag is ignored.
	 *
	 * bit 2:	Flag '.', use @ref FMT_PRECISION_ON. This flag applies to s,
	 * d, i, u, x, and X conversions.
	 *
	 * bit 3:	Flag ' ', use @ref FMT_PLUS_SIGN_SPACE. This flag applies to
	 * d and i conversions. If @ref FMT_PLUS_SIGN_SHOW is set, this flag
	 * is ignored.
	 *
	 * bit 4:	Flag '+', use @ref FMT_PLUS_SIGN_SHOW. This flag applies to
	 * d and i conversions and overrides @ref FMT_PLUS_SIGN_SPACE.
	 *
	 * bit 5:	Flag '#', use @ref FMT_ALT_FORM. This flag applies to x
	 * and X conversions.
	 *
	 * bits 6-7: unused.
	 */
	unsigned char	flags;
}	t_format;

/**
 * @brief A structure containing the parts of a decimal conversion.
 */
typedef struct s_dec_parts
{
	/**
	 * @brief The padding length, in bytes.
	 */
	size_t			pad_len;
	/**
	 * @brief The number length, in bytes.
	 */
	size_t			num_len;
	/**
	 * @brief The absolute value of the number to print.
	 */
	unsigned int	value;
	/**
	 * @brief The sign character. This is '-' if the number is
	 * negative, or '+' or ' ' if the corresponding flag is set
	 * in the @ref t_format struct. Otherwise, this is 0.
	 */
	char			sign_char;
}	t_dec_parts;

/**
 * @brief A structure containing the parts of a hexadecimal conversion.
 */
typedef struct s_hex_parts
{
	/**
	 * @brief The padding length, in bytes.
	 */
	size_t			pad_len;
	/**
	 * @brief The number length, in bytes.
	 */
	size_t			num_len;
	/**
	 * @brief The prefix length, in bytes. This is either 0 or 2,
	 * depending on the @ref FMT_ALT_FORM flag in the @ref t_format
	 * struct.
	 */
	size_t			prefix_len;
	/**
	 * @brief The absolute value of the number to be printed.
	 */
	unsigned int	value;
}	t_hex_parts;

/**
 * @brief Loads @p n into @p buf, up to a total of @p ndigits,
 * as a lowercase hexadecimal number.
 * @param buf The buffer to store data into.
 * @param n The number to write.
 * @param ndigits The number of digits needed to print @p n.
 */
void		ft_xtoa_stack(char *buf, unsigned long n, size_t ndigits);

/**
 * @brief Loads @p n into @p buf, up to a total of @p ndigits,
 * as an uppercase hexadecimal number.
 * @param buf The buffer to store data into.
 * @param n The number to write.
 * @param ndigits The number of digits needed to print @p n.
 */
void		ft_xxtoa_stack(char *buf, unsigned long n, size_t ndigits);

/**
 * @brief Loads @p n into @p buf, up to a total of @p ndigits,
 * as a decimal number.
 * @param buf The buffer to store data into.
 * @param n The number to write.
 * @param ndigits The number of digits needed to print @p n.
 */
void		ft_utoa_stack(char *buf, unsigned long n, size_t ndigits);

/**
 * @brief Counts the number of digits it would take to print
 * @p n as a base 10 unsigned integer.
 * @param n The number whose digits will be counted.
 * @returns The number of digits in base 10.
 */
size_t		count_digits_10(unsigned long n);

/**
 * @brief Counts the number of digits it would take to print
 * @p n as a base 10 signed integer.
 * @param n The number whose digits will be counted.
 * @returns The number of digits in base 10.
 */
size_t		count_digits_10i(long n);

/**
 * @brief Counts the number of digits it would take to print
 * @p n as a base 16 unsigned integer.
 * @param n The number whose digits will be counted.
 * @returns The number of digits in base 10.
 */
size_t		count_digits_16(unsigned long n);

/**
 * @brief Parses a region of the formatted string into format options.
 * @param s The format string region.
 * @param f The printing options.
 * @param args The va_list from @ref ft_printf.
 * @returns A pointer to the first character in the format string
 * after this conversion specifier.
 */
const char	*parse_format(const char *s, t_format *f, va_list args);

/**
 * @brief Calculates the total length of the final formatted string
 * without writing it.
 * @param format The format string.
 * @param args The va_list from @ref ft_printf.
 * @return The total length of the string that *would* be printed.
 */
size_t		get_total_len(const char *format, va_list args);

/**
 * @brief Calculates the length of a "%c" conversion.
 * @param f The printing options.
 * @returns The length to print, in bytes.
 */
size_t		conv_len_c(const t_format *f);

/**
 * @brief Calculates the length of a "%d" or "%i" conversion.
 * @param f The printing options.
 * @param d The number to be printed.
 * @returns The length to print, in bytes.
 */
size_t		conv_len_d(const t_format *f, int d);

/**
 * @brief Calculates the length of a "%u" conversion.
 * @param f The printing options.
 * @param u The number to be printed.
 * @returns The length to print, in bytes.
 */
size_t		conv_len_u(const t_format *f, unsigned int u);

/**
 * @brief Calculates the length of a "%s" conversion.
 * @param f The printing options.
 * @param s The string to be printed.
 * @returns The length to print, in bytes.
 */
size_t		conv_len_s(const t_format *f, const char *s);

/**
 * @brief Calculates the length of a "%p" conversion.
 * @param f The printing options.
 * @param p The address to be printed.
 * @returns The length to print, in bytes.
 */
size_t		conv_len_p(const t_format *f, const void *p);

/**
 * @brief Calculates the length of a "%x" or "%X" conversion.
 * @param f The printing options.
 * @param x The number to be printed.
 * @returns The length to print, in bytes.
 */
size_t		conv_len_x(const t_format *f, unsigned int x);

/**
 * @brief Loads the entire formatted string into a buffer.
 * @param buf The buffer to store the output.
 * @param format The format string.
 * @param args The va_list from @ref ft_printf.
 */
void		load_string(char *buf, const char *format, va_list args);

/**
 * @brief Loads a "%c" conversion's output into a buffer.
 * @param buf The output buffer.
 * @param f The printing options.
 * @param c The character to print.
 * @returns A pointer to the first location in @p buf after the
 * conversion's output.
 */
char		*load_conv_c(char *buf, const t_format *f, char c);

/**
 * @brief Loads a "%s" conversion's output into a buffer.
 * @param buf The output buffer.
 * @param f The printing options.
 * @param s The string to print.
 * @returns A pointer to the first location in @p buf after the
 * conversion's output.
 */
char		*load_conv_s(char *buf, const t_format *f, const char *s);

/**
 * @brief Loads a "%p" conversion's output into a buffer.
 * @param buf The output buffer.
 * @param f The printing options.
 * @param s The address to print.
 * @returns A pointer to the first location in @p buf after the
 * conversion's output.
 */
char		*load_conv_p(char *buf, const t_format *f, void *p);

/**
 * @brief Loads a "%d" or "%i" conversion's output into a buffer.
 * @param buf The output buffer.
 * @param f The printing options.
 * @param d The number to print.
 * @returns A pointer to the first location in @p buf after the
 * conversion's output.
 */
char		*load_conv_d(char *buf, const t_format *f, int u);

/**
 * @brief Loads a "%u" conversion's output into a buffer.
 * @param buf The output buffer.
 * @param f The printing options.
 * @param u The number to print.
 * @returns A pointer to the first location in @p buf after the
 * conversion's output.
 */
char		*load_conv_u(char *buf, const t_format *f, unsigned int u);

/**
 * @brief Loads a "%x" conversion's output into a buffer.
 * @param buf The output buffer.
 * @param f The printing options.
 * @param u The number to print.
 * @returns A pointer to the first location in @p buf after the
 * conversion's output.
 */
char		*load_conv_x(char *buf, const t_format *f, unsigned int u);

/**
 * @brief Loads a "%X" conversion's output into a buffer.
 * @param buf The output buffer.
 * @param f The printing options.
 * @param u The number to print.
 * @returns A pointer to the first location in @p buf after the
 * conversion's output.
 */
char		*load_conv_xx(char *buf, const t_format *f, unsigned int u);

#endif
