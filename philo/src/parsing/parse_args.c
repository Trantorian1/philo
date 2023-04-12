/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:16:40 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/12 10:17:38 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

#include <stdlib.h>

int32_t	parse_args(int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
