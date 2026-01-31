/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:52:55 by aalkaff           #+#    #+#             */
/*   Updated: 2026/01/31 20:10:20 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>

# ifndef BUFFER_SIZE
/**
 * @brief The number of bytes to read from the file descriptor.
 */
#  define BUFFER_SIZE		4096
# endif

# ifndef FD_MAX
/**
 * @brief The maximum number of file descriptors a process
 * can have at once.
 */
#  define FD_MAX			4096
# endif

# define GNL_READ_FAILED	0
# define GNL_CONTINUE		1
# define GNL_REACHED_EOF	2

/**
 * @brief An analog to the C++ std::vector container that grows
 * geometrically and needs O(log n) allocation operations.
 */
typedef struct s_vector
{
	/**
	 * @brief The actual vector.
	 */
	char	*data;

	/**
	 * @brief The number of bytes used by vector elements.
	 */
	size_t	size;

	/**
	 * @brief The amount of memory allocated to the vector, in bytes.
	 */
	size_t	capacity;
}	t_vector;


void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

/**
 * @brief Initializes a @ref t_vector struct.
 * @param vec A pointer to the @ref t_vector struct.
 * @param stash The leftover stash from the previous @ref
 * get_next_line() call. The stash is loaded into @p vec. If
 * this parameter points to NULL, it is ignored. The function
 * frees the stash and sets it to NULL.
 * @returns On success, the function returns 1.
 *
 * On error, the function returns 0.
 */
int		vec_init(t_vector *vec, char **stash);

/**
 * @brief Checks if @p vec has enough space to store an object sized
 * @p extra_bytes. If the space is not enough, the function doubles
 * the size of @p vec to assure safe loading.
 * @param vec A pointer to the @ref t_vector struct to test.
 * @param extra_bytes The number of requested bytes.
 */
int		vec_ensure_capacity(t_vector *vec, size_t extra_bytes);

#endif
