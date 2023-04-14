/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_runner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:53:12 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/14 18:48:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_runner.h"

#include "s_philo.h"
#include "e_philo_state.h"
#include "table.h"
#include "philo_do_nothing.h"
#include "philo_pickup_fork.h"
#include "philo_eat.h"
#include "philo_sleep.h"
#include "philo_think.h"

typedef int32_t					(*t_f_philo_state)(t_s_philo *philo);

static const t_f_philo_state	g_state_machine[E_PHILO_STATE_SIZE + 1] = {
	&philo_do_nothing,
	&philo_pickup_fork,
	&philo_eat,
	&philo_sleep,
	&philo_think,
	&philo_do_nothing,
	&philo_do_nothing,
	&philo_do_nothing
};

void	*philo_runner(void *data)
{
	t_s_philo	*philo;

	philo = (t_s_philo *)data;
	philo->state = STATE_THINKING;
	while (table_get()->game_state != END)
		g_state_machine[philo->state](philo);
	return (philo);
}
