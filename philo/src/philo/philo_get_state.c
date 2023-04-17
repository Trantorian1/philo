/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_get_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:14:04 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 14:17:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_get_state.h"

#include <pthread.h>

t_e_philo_state	philo_get_state(t_s_philo *philo)
{
	t_e_philo_state	state;

	if (philo == NULL)
		return (STATE_ERROR);
	pthread_mutex_lock(&philo->lock_state);
	state = philo->state;
	pthread_mutex_unlock(&philo->lock_state);
	return (state);
}
