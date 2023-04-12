/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bus_send.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:05:22 by                   #+#    #+#             */
/*   Updated: 2023/04/11 19:22:51 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_BUS_SEND_H
# define MESSAGE_BUS_SEND_H

# include <stddef.h>
# include <stdint.h>

# include "e_philo_state.h"

int32_t	message_bus_send(size_t id, t_e_philo_state state);

#endif
