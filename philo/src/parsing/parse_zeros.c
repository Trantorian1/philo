/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_zeros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:39:14 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/12 11:42:34 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_zeros.h"

#include <stdlib.h>

int32_t	parse_zeros(char **str_int)
{
	if (str_int == NULL || *str_int == NULL)
		return (EXIT_FAILURE);
	while (**str_int != '\0' && **str_int == '0')
		(*str_int)++;
	return (EXIT_SUCCESS);
}
