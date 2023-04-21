/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:35:09 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 10:36:42 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_think.h"

#include <stdlib.h>
#include <unistd.h>

#include "table.h"
#include "table_request.h"
#include "philo_set_state.h"
#include "time_millis.h"
#include "error_philo.h"
#include "libft.h"

int32_t	philo_think(t_s_philo *philo)
{
	int64_t		time_curr;
	int64_t		time_delta;
	t_s_table	*table;

	if (philo == NULL)
		return (EXIT_FAILURE);
	if (time_millis(&time_curr) != EXIT_SUCCESS)
		return (error_philo(philo, STATE_ERROR, -1));
	table = table_get();
	time_delta = time_curr - philo->time_last_meal;
	if (time_delta >= table->args->time_death)
		return (error_philo(philo, STATE_DEAD, time_curr));
	if (table_request(philo) == true)
		return (philo_set_state(philo, STATE_PICK_FORK, time_curr));
	return (EXIT_SUCCESS);
}
