/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:50:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/18 10:49:54 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_philo.h"

#include <stdlib.h>
#include <pthread.h>

#include "e_philo_state.h"
#include "philo_set_state.h"

int32_t	error_philo(t_s_philo *philo, t_e_philo_state state, int64_t time)
{
	if (philo == NULL)
		return (EXIT_FAILURE);
	pthread_mutex_lock(&philo->lock_attr);
	philo->time_last_meal = time;
	philo->ownership = false;
	pthread_mutex_unlock(&philo->lock_attr);
	philo_set_state(philo, state, time);
	return (EXIT_FAILURE);
}
