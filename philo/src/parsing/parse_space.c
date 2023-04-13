/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:28:20 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/12 11:35:10 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_space.h"

#include <stdlib.h>

#include "libft.h"

int32_t	parse_space(char **str_int)
{
	if (str_int == NULL || *str_int == NULL)
		return (EXIT_FAILURE);
	while (**str_int != '\0' && ft_isspace(**str_int))
		(*str_int)++;
	return (EXIT_SUCCESS);
}
