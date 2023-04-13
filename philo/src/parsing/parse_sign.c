/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:33:30 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/12 11:38:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_sign.h"

#include <stdlib.h>

int32_t	parse_sign(char **str_int, int8_t *sign)
{
	if (str_int == NULL || *str_int == NULL)
		return (EXIT_FAILURE);
	if (**str_int == '-')
	{
		(*str_int)++;
		*sign = -1;
	}
	if (**str_int == '+')
	{
		(*str_int)++;
		*sign = 1;
	}
	else
		*sign = 1;
	return (EXIT_SUCCESS);
}
