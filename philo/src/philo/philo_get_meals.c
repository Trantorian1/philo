/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_get_meals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:04:24 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/18 10:06:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_get_meals.h"

#include <pthread.h>

int32_t	philo_get_meals(t_s_philo *philo)
{
	int32_t	meals;

	if (philo == NULL)
		return (-1);
	pthread_mutex_lock(&philo->lock_attr);
	meals = philo->meals;
	pthread_mutex_unlock(&philo->lock_attr);
	return (meals);
}
