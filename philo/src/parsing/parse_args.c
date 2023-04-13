/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:16:40 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/13 10:54:47 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

#include <stdbool.h>
#include <stdlib.h>

#include "parse_int32.h"

static int32_t	initialise_endptrs(char ***endptrs, int32_t argc)
{
	*endptrs = malloc((size_t)(argc - 1) * sizeof(**endptrs));
	return (endptrs == NULL);
}

static int32_t	validate_parsing(int32_t argc, char **argv, char **endptrs)
{
	size_t	index;

	index = (size_t)(-1);
	while (++index < (size_t)(argc - 1))
		if (*argv[index + 1] == '\0' || *endptrs[index] != '\0')
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_s_args	*parse_args(int32_t argc, char **argv)
{
	char			**endptrs;
	static t_s_args	args;

	if (argc < 5)
		return (NULL);
	endptrs = NULL;
	if (initialise_endptrs(&endptrs, argc) == EXIT_FAILURE)
		return ((void)free(endptrs), NULL);
	args.philo_count = parse_int32(argv[1], &endptrs[0]);
	args.time_death = parse_int32(argv[2], &endptrs[1]);
	args.time_eat = parse_int32(argv[3], &endptrs[2]);
	args.time_sleep = parse_int32(argv[4], &endptrs[3]);
	if (argc < 6)
	{
		if (validate_parsing(argc, argv, endptrs) == EXIT_FAILURE)
			return ((void)free(endptrs), NULL);
		free(endptrs);
		return (&args);
	}
	args.meal_target = parse_int32(argv[5], &endptrs[4]);
	if (validate_parsing(argc, argv, endptrs) == EXIT_FAILURE)
		return ((void)free(endptrs), NULL);
	free(endptrs);
	return (&args);
}
