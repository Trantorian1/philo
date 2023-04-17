/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_set_state.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:09:21 by                   #+#    #+#             */
/*   Updated: 2023/04/17 16:09:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_SET_STATE_H
# define PHILO_SET_STATE_H

# include <stdint.h>
# include "s_philo.h"

int32_t	philo_set_state(t_s_philo *philo, t_e_philo_state state, int64_t time);

#endif
