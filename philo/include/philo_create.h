/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:13:25 by                   #+#    #+#             */
/*   Updated: 2023/04/10 15:13:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_CREATE_H
# define PHILO_CREATE_H

# include "s_philo.h"

t_s_philo	*philo_create(
	t_s_philo *philo,
	t_s_promise *promise,
	t_f_runner *runner);

#endif
