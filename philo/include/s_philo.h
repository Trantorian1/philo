/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:08:42 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 18:14:10 by emcnab           ###   ########.fr       */
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

typedef struct s_philo
{
	int32_t			id;
	int32_t			meals;
	bool			owner;
	int64_t			time_last_meal;
	t_e_philo_state	state;
	pthread_mutex_t	lock_state;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	fork_right;
	pthread_t		thread;
	t_f_runner		*runner;
}	t_s_philo;

#endif // !S_PHILO_H
