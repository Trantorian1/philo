/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:15:16 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/22 16:42:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_args.h"

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

#define HELP "┌───────────────────────────────────────────────────────────────┐\
			\n│ -------------------- P H I L O S O P H E R ------------------ │\
			\n├───────────────────────────────────────────────────────────────┤\
			\n│                                                               │\
			\n│ - project by Eliot McNab                                      │\
			\n│                                                               │\
			\n│  This is an implementation of Dijkstra's dining philosopher   │\
			\n│  problem. The goal of this solution was experimenting with    │\
			\n│  the use of monitors in a multithreaded environment as a      │\
			\n│  means to synchronise data access across threads while        │\
			\n│  maintaining high performance and thread safety.              │\
			\n│                                                               │\
			\n│  command:                                                     │\
            \n│   ./philo philo_count time_to_die time_to_eat time_to_sleep   │\
			\n│           [target_meals]                                      │\
			\n│                                                               │\
			\n│  parameters:                                                  │\
			\n│   time_to_die    [0; INT32_MAX]                               │\
			\n│                  Number of philosophers to simulate.          │\
			\n│                                                               │\
			\n│   time_to_die    [0; INT32_MAX]                               │\
			\n│                  Amount of time (in milliseconds) it takes    │\
			\n│                  for a philosopher to die.                    │\
			\n│                                                               │\
			\n│   time_to_eat    [1; INT64_MAX]                               │\
			\n│                  amount of time (in milliseconds) it takes    │\
			\n│                  for a philosopher to eat.                    │\
			\n│                                                               │\
			\n│   time_to_sleep  [1; INT64_MAX]                               │\
			\n│                  amount of time (in milliseconds) it takes    │\
			\n│                  for a philosopher to sleep.                  │\
			\n│                                                               │\
			\n│   target_meals   [1; INT32_MAX]                               │\
			\n│                  number of meals each philosopher must eat    │\
			\n│                  for the simulation to stop. If unspecified,  │\
			\n│                  simulation will go on forever.               │\
			\n│                                                               │\
			\n└───────────────────────────────────────────────────────────────┘"

int32_t	error_args(void)
{
	ft_putendl_fd(HELP, STDOUT_FILENO);
	return (EXIT_FAILURE);
}
