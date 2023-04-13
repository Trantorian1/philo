/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:15:16 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/13 19:28:31 by emcnab           ###   ########.fr       */
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
			\n│  This is a test project involving the use of monitors in a    │\
			\n│  multithreaded environment as a means to synchronise data     │\
			\n│  access across threads while maintaining high performance     │\
			\n│  and thread safety.                                           │\
			\n│                                                               │\
			\n│  command:                                                     │\
            \n│   ./philo philo_count time_to_die time_to_eat time_to_sleep   │\
			\n│                       [target_meals]                          │\
			\n│                                                               │\
			\n│  parameters:                                                  │\
			\n│   time_to_die    amount of time (in milliseconds) it takes    │\
			\n│                  for a philosopher to die.                    │\
			\n│   time_to_eat    amount of time (in milliseconds) it takes    │\
			\n│                  for a philosopher to eat.                    │\
			\n│   time_to_sleep  amount of time (in milliseconds) it takes    │\
			\n│                  for a philosopher to sleep.                  │\
			\n│   target_meals   number of meals each philosopher must eat    │\
			\n│                  for the simulation to stop. If unspecified,  │\
			\n│                  simulation will go on forever.               │\
			\n│                                                               │\
			\n└───────────────────────────────────────────────────────────────┘"

int32_t	error_args(void)
{
	ft_putendl_fd(HELP, STDOUT_FILENO);
	return (EXIT_FAILURE);
}
