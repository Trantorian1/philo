/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_philo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:00:01 by                   #+#    #+#             */
/*   Updated: 2023/04/17 16:01:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_PHILO_H
# define ERROR_PHILO_H

# include <stdint.h>

# include "s_philo.h"
# include "e_philo_state.h"

int32_t	error_philo(t_s_philo *philo, t_e_philo_state state, int64_t time);

#endif
