/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int32.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:27:19 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 17:31:33 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_int32.h"

#include <stdlib.h>

#include "parse_space.h"
#include "parse_sign.h"
#include "parse_zeros.h"
#include "fits_in_int32.h"
#include "libft.h"

/**
 * @brief Parse an int32_t, overflows are considered as errors.
 *
 * Valid entry formats are:
 * whitespaces -> sign -> zeros -> digits
 *
 * If the int being described in the string does not fit in an int32_t, returns
 * 0 instead.
 *
 * @param str_int (char *): String representation of an int.
 * @param endptr (char **): Will be set to the last character to be parsed. '\0'
 * means that no other character was found after the last digit and shoudl be
 * treated as the only success case.
 * @return (int32_t): int representation of (str_int).
 */
int32_t	parse_int32(char *str_int, char **endptr)
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
	if (fits_in_int32(*cursor, endptr, sign) == EXIT_FAILURE
		|| **endptr != '\0')
		return (0);
	return (sign * ft_atoi(*cursor));
}
