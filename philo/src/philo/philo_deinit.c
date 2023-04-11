/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_deinit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:19:00 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 17:28:23 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_deinit.h"

#include <stdlib.h>

// TODO: Make sure this works if philo->fork_left or philo->fork_right haven't
// been initialised.
int32_t	philo_deinit(t_s_philo *philo)
{
	if (philo == NULL)
		return (EXIT_FAILURE);
	pthread_mutex_destroy(&philo->fork_left);
	pthread_mutex_destroy(&philo->fork_right);
	return (EXIT_SUCCESS);
}
