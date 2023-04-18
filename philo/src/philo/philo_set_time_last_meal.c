/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_set_time_last_meal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:28:02 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/18 09:30:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_set_time_last_meal.h"

#include <stdlib.h>
#include <pthread.h>

int32_t	philo_set_time_last_meal(t_s_philo *philo, int64_t time)
{
	if (philo == NULL || time < 0)
		return (EXIT_FAILURE);
	pthread_mutex_lock(&philo->lock_attr);
	philo->time_last_meal = time;
	pthread_mutex_unlock(&philo->lock_attr);
	return (EXIT_SUCCESS);
}
