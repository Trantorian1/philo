/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:16:40 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 17:42:12 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

#include <stdbool.h>
#include <stdlib.h>

#include "parse_int32.h"
#include "parse_int64.h"

static int32_t	initialise_endptrs(char ***endptrs, int32_t argc)
{
	*endptrs = malloc((size_t)(argc - 1) * sizeof(**endptrs));
	return (endptrs == NULL);
}

static int32_t	validate_parsing(
	t_s_args *args,
	int32_t argc,
	char **argv,
	char **endptrs)
{
	size_t	index;

	if (args->philo_count <= 0)
		return (EXIT_FAILURE);
	if (args->time_death < 0)
		return (EXIT_FAILURE);
	if (args->time_eat < 1)
		return (EXIT_FAILURE);
	if (args->time_sleep < 1)
		return (EXIT_FAILURE);
	if (argc > 5 && args->meal_target < 1)
		return (EXIT_FAILURE);
	index = (size_t)(-1);
	while (++index < (size_t)(argc - 1))
		if (*argv[index + 1] == '\0' || *endptrs[index] != '\0')
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * @brief Handles parsing program arguments
 *
 * @return (t_s_args *): Argument structure.
 */
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
	args.time_death = parse_int64(argv[2], &endptrs[1]);
	args.time_eat = parse_int64(argv[3], &endptrs[2]);
	args.time_sleep = parse_int64(argv[4], &endptrs[3]);
	args.meal_target = -1;
	if (argc < 6)
	{
		if (validate_parsing(&args, argc, argv, endptrs) == EXIT_FAILURE)
			return ((void)free(endptrs), NULL);
		free(endptrs);
		return (&args);
	}
	args.meal_target = parse_int32(argv[5], &endptrs[4]);
	if (validate_parsing(&args, argc, argv, endptrs) == EXIT_FAILURE)
		return ((void)free(endptrs), NULL);
	free(endptrs);
	return (&args);
}
