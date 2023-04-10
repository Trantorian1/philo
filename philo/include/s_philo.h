/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:08:42 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 14:32:02 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PHILO_H
# define S_PHILO_H

# include <pthread.h>

# include "e_philo_state.h"
# include "s_promise.h"
# include "f_runner.h"

typedef struct s_philo
{
	t_e_philo_state	state;
	pthread_t		thread;
	t_s_promise		*promise;
	t_f_runner		*runner;
}	t_s_philo;

#endif // !S_PHILO_H
