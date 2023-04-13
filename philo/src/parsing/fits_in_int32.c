/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fits_in_int32.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:42:04 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/13 17:16:05 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fits_in_int32.h"

#include <stdlib.h>

#include "libft.h"

#define INT_LEN 10
#define INT_MIN_STR "2147483648"
#define INT_MAX_STR "2147483647"

static int32_t	check_arguments(char *str_int, char **endptr, int8_t sign)
{
	if (endptr == NULL)
		return (EXIT_FAILURE);
	if (str_int == NULL)
	{
		*endptr = NULL;
		return (EXIT_FAILURE);
	}
	if (sign != 1 && sign != -1)
	{
		*endptr = str_int;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static uint8_t	get_number_len(char *str_int)
{
	uint8_t	size;

	size = 0;
	while (size < INT_LEN && ft_isdigit(*str_int))
	{
		str_int++;
		size++;
	}
	return (size);
}

static int32_t	parse_failure(char **endptr, char *target)
{
	*endptr = target;
	return (EXIT_FAILURE);
}

static int32_t	parse_success(char **endptr, char *target)
{
	*endptr = target;
	return (EXIT_SUCCESS);
}

/**
 * @brief Determines wheter the string representation of a number fints in a
 * 32-bit integer.
 *
 * @param str_int (char *): string to check. Should only contain digits.
 * @param endptr (char **): pointer to the last character in the string to have
 * been parsed.
 * @param sign (int8_t): sign associated to str_int.
 * @return (int32_t): EXIT_SUCCESS if str_int fits in a 32-bit integer,
 * EXIT_FAILURE otherwise.
 */
int32_t	fits_in_int32(char *str_int, char **endptr, int8_t sign)
{
	uint8_t	size;

	if (check_arguments(str_int, endptr, sign) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	size = get_number_len(str_int);
	if (size < INT_LEN)
		return (parse_success(endptr, str_int + size));
	else if (size > INT_LEN)
		return (parse_failure(endptr, str_int + INT_LEN));
	else if (sign == -1 && ft_strcmp(INT_MIN_STR, str_int) < 0)
		return (parse_failure(endptr, str_int + size));
	else if (sign == 1 && ft_strcmp(INT_MAX_STR, str_int) < 0)
		return (parse_failure(endptr, str_int + size));
	return (parse_success(endptr, str_int + size));
}
