/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_message.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:56:50 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 17:11:51 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MESSAGE_H
# define S_MESSAGE_H

# include <stdint.h>

# include "e_philo_state.h"

/**
 * @typedef s_message
 * @brief A state change message 
 *
 * Describes a change in state for a philosopher, where id is the ID of the
 * philosopher, time is the time of the state change and state is the
 * philosopher's new state.
 */
typedef struct s_message
{
	int32_t			id;
	int64_t			time;
	t_e_philo_state	state;
}	t_s_message;

#endif
