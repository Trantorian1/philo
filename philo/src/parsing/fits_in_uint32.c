/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fits_in_uint32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:52:55 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/13 17:17:30 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fits_in_uint32.h"

#include <stdlib.h>
#include <sys/types.h>

#include "libft.h"

#define UINT_LEN 10
#define UINT_MAX_STR "4294967295"

static int32_t	check_arguments(char *str_int, char **endptr, int8_t sign)
{
	if (endptr == NULL)
		return (EXIT_FAILURE);
	if (str_int == NULL)
	{
		*endptr = NULL;
		return (EXIT_FAILURE);
	}
	if (sign != 1)
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
	while (size < UINT_LEN && ft_isdigit(*str_int))
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

int32_t	fits_in_uint32(char *str_uint, char **endptr, int8_t sign)
{
	uint8_t	size;

	if (check_arguments(str_uint, endptr, sign) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	size = get_number_len(str_uint);
	if (size < UINT_LEN)
		return (parse_success(endptr, str_uint + size));
	else if (size > UINT_LEN)
		return (parse_failure(endptr, str_uint + UINT_LEN));
	else if (ft_strcmp(UINT_MAX_STR, str_uint) < 0)
		return (parse_failure(endptr, str_uint + size));
	return (parse_success(endptr, str_uint + size));
}
