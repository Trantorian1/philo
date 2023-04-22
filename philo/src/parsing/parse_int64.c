/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:49:56 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 17:31:20 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_int64.h"

#include <stdlib.h>

#include "parse_space.h"
#include "parse_sign.h"
#include "parse_zeros.h"
#include "fits_in_int64.h"
#include "libft.h"

/**
 * @brief Parse an int64_t, overflows are considered as errors.
 *
 * Valid entry formats are:
 * whitespaces -> sign -> zeros -> digits
 *
 * If the int being described in the string does not fit in an int64_t, returns
 * 0 instead.
 *
 * @param str_int (char *): String representation of an int.
 * @param endptr (char **): Will be set to the last character to be parsed. '\0'
 * means that no other character was found after the last digit and shoudl be
 * treated as the only success case.
 * @return (int64_t): int representation of (str_int).
 */
int64_t	parse_int64(char *str_int, char **endptr)
{
	char	**cursor;
	int8_t	sign;

	if (str_int == NULL || endptr == NULL)
		return (EXIT_FAILURE);
	if (*str_int == '\0')
	{
		*endptr = str_int;
		return (EXIT_FAILURE);
	}
	cursor = &str_int;
	parse_space(cursor);
	parse_sign(cursor, &sign);
	parse_zeros(cursor);
	if (fits_in_int64(*cursor, endptr, sign) == EXIT_FAILURE
		|| **endptr != '\0')
		return (0);
	return (sign * ft_atol(*cursor));
}
