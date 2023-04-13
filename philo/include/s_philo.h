/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:08:42 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/11 19:04:14 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PHILO_H
# define S_PHILO_H

# include <pthread.h>
# include <stddef.h>

# include "e_philo_state.h"
# include "s_promise.h"
# include "f_runner.h"

typedef struct s_philo
{
	size_t			id;
	t_e_philo_state	state;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	fork_right;
	pthread_t		thread;
	t_f_runner		*runner;
}	t_s_philo;

#endif // !S_PHILO_H