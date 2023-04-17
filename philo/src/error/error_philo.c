/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:50:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 16:01:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_philo.h"

#include <stdlib.h>

#include "e_philo_state.h"
#include "philo_set_state.h"

int32_t	error_philo(t_s_philo *philo, t_e_philo_state state, int64_t time)
{
	if (philo == NULL)
		return (EXIT_FAILURE);
	philo_set_state(philo, state, time);
	return (EXIT_FAILURE);
}
