/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_message_bus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:58:46 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 17:10:30 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MESSAGE_BUS_H
# define S_MESSAGE_BUS_H

# define MESSAGE_BUS_SIZE 1024

# include <stddef.h>
# include <pthread.h>

# include "s_message.h"

/**
 * @typedef s_message_bus
 * @brief Multithreaded message bus
 *
 * Multithreaded message bus simgleton for blocking display across threads.
 * Messages consist of a state, an ID and a time and are stored in a circular
 * buffer, which is periodically flushed by the main thread. This avoids system
 * calls inside of threads and simplifies display synchronisation.
 */
typedef struct s_message_bus
{
	size_t			size;
	t_s_message		*tail;
	t_s_message		*head;
	pthread_mutex_t	lock_tail;
	pthread_mutex_t	lock_head;
	pthread_mutex_t	lock_size;
	pthread_mutex_t	lock_write;
	pthread_mutex_t	lock_flush;
	t_s_message		buffer_start[MESSAGE_BUS_SIZE];
}	t_s_message_bus;

#endif
