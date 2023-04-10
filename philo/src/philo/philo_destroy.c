/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:16:00 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 14:34:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_destroy.h"

#include <pthread.h>
#include <stdlib.h>

void	*philo_destroy(t_s_philo *philo)
{
	if (philo == NULL)
		return (NULL);
	philo->promise = NULL;
	philo->runner = NULL;
	free(philo);
	return (NULL);
}
