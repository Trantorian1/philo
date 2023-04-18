/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_set_ownership.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:39:32 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/18 10:41:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_set_ownership.h"

#include <stdlib.h>
#include <pthread.h>

int32_t	philo_set_ownership(t_s_philo *philo, bool ownership)
{
	if (philo == NULL)
		return (EXIT_FAILURE);
	pthread_mutex_lock(&philo->lock_attr);
	philo->ownership = ownership;
	pthread_mutex_unlock(&philo->lock_attr);
	return (EXIT_SUCCESS);
}
