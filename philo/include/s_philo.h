/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:08:21 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 17:03:51 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PHILO_H
# define S_PHILO_H

# include <pthread.h>
# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>

# include "e_philo_state.h"
# include "f_runner.h"

/**
 * @typedef s_philo
 * @brief A philosopher in Dijkstra's dining philosophers problem
 *
 * Philosphers are sat down together at a table, with one fork per philosopher.
 * Each philospher needs two forks to eat, and as such forks needs to be shared
 * between neighbours. It takes a philosopher x time to eat, after which
 * they must sleep for y time. If a philospher has not eaten in z time, then
 * they die. Contants x, y and z are provided as arguments at the start of the
 * program.
 */
typedef struct s_philo
{
	int32_t			id;
	int32_t			meals;
	int64_t			time_last_meal;
	bool			ownership;
	bool			init_state;
	bool			init_attr;
	t_e_philo_state	state;
	pthread_mutex_t	lock_state;
	pthread_mutex_t	lock_attr;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	fork_right;
	struct s_philo	*neighbour_left;
	struct s_philo	*neighbour_right;
	t_f_runner		*runner;
	pthread_t		thread;
}	t_s_philo;

#endif // !S_PHILO_H
