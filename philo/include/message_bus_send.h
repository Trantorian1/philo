/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bus_send.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:40:58 by                   #+#    #+#             */
/*   Updated: 2023/04/11 17:41:34 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_BUS_SEND_H
# define MESSAGE_BUS_SEND_H

# include <stdint.h>

# include "e_philo_state.h"

int32_t	message_bus_send(int32_t id, t_e_philo_state state);
int32_t	message_bus_send(int32_t id, t_e_philo_state state);

#endif
