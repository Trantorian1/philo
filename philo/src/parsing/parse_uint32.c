/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_uint32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:48:24 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/13 17:28:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_uint32.h"

#include <stdlib.h>

#include "fits_in_uint32.h"
#include "parse_space.h"
#include "parse_sign.h"
#include "parse_zeros.h"
#include "libft.h"

uint32_t	parse_uint32(char *str_int, char **endptr)
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
	if (fits_in_uint32(*cursor, endptr, sign) == EXIT_FAILURE
		|| **endptr == '\0')
		return (0);
	return (ft_atoui(*cursor));
}
