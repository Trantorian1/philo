/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:14:08 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 16:16:49 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_destroy.h"

#include <stdlib.h>
#include <pthread.h>

void	*philo_destroy(t_s_philo *philo)
{
	if (philo == NULL)
		return (NULL);
	if (philo->init_state == true)
		pthread_mutex_destroy(&philo->lock_state);
	if (philo->init_attr == true)
		pthread_mutex_destroy(&philo->lock_attr);
	philo->neighbour_left = NULL;
	philo->neighbour_right = NULL;
	philo->runner = NULL;
	return (NULL);
}
