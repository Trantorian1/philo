/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:30:51 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 15:55:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sleep.h"

#include <stdlib.h>
#include <unistd.h>

#include "e_philo_state.h"
#include "error_philo.h"
#include "table.h"
#include "philo_set_state.h"
#include "table_get_time.h"
#include "time_millis.h"
#include "libft.h"

int32_t	philo_sleep(t_s_philo *philo)
{
	int64_t		time_curr;
	int64_t		time_delta;
	t_s_args	*table_args;

	if (philo == NULL)
		return (EXIT_FAILURE);
	time_curr = table_get_time();
	table_args = table_get()->args;
	time_delta = time_curr - philo->time_last_meal;
	if (time_delta > table_args->time_death)
		return (error_philo(philo, STATE_DEAD, time_curr));
	if (time_delta - table_args->time_eat < table_args->time_sleep)
		return (EXIT_SUCCESS);
	return (philo_set_state(philo, STATE_THINKING, time_curr));
}
