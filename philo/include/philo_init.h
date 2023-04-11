/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:13:25 by                   #+#    #+#             */
/*   Updated: 2023/04/10 15:46:33 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_CREATE_H
# define PHILO_CREATE_H

# include <stddef.h>
# include <stdint.h>

# include "s_philo.h"

int32_t	philo_init(
	t_s_philo *philo,
	size_t id,
	t_f_runner *runner);

#endif
