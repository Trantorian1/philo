/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fits_in_int64.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:54:57 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 12:12:45 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fits_in_int64.h"

#include <stdlib.h>

#include "libft.h"

#define LONG_LEN 19
#define LONG_MIN_STR "9223372036854775808"
#define LONG_MAX_STR "9223372036854775807"

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
	while (size < LONG_LEN && ft_isdigit(*str_int))
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

int64_t	fits_in_int64(char *str_int, char **endptr, int8_t sign)
{
	uint8_t	size;

	if (check_arguments(str_int, endptr, sign) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	size = get_number_len(str_int);
	if (size < LONG_LEN)
		return (parse_success(endptr, str_int + size));
	else if (size > LONG_LEN)
		return (parse_failure(endptr, str_int + size));
	else if (sign == -1 && ft_strcmp(LONG_MIN_STR, str_int) < 0)
		return (parse_failure(endptr, str_int + size));
	else if (sign == 1 && ft_strcmp(LONG_MAX_STR, str_int) < 0)
		return (parse_failure(endptr, str_int + size));
	return (parse_success(endptr, str_int + size));
}
