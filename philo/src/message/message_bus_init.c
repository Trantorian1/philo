/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bus_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:30:57 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/11 17:37:23 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_bus_init.h"

#include <stdlib.h>

#include "message_bus_get.h"

#define ERROR_MUTEX_HEAD 1
#define ERROR_MUTEX_WRITE 2

static int32_t	error_free(t_s_message_bus *message_bus, int32_t error_code)
{
	if (error_code >= ERROR_MUTEX_HEAD)
		pthread_mutex_destroy(&message_bus->tail_lock);
	if (error_code == ERROR_MUTEX_WRITE)
		pthread_mutex_destroy(&message_bus->write_lock);
	return (EXIT_FAILURE);
}

int32_t	message_bus_init(void)
{
	t_s_message_bus	*message_bus;

	message_bus = message_bus_get();
	if (pthread_mutex_init(&message_bus->tail_lock, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&message_bus->head_lock, NULL) != EXIT_SUCCESS)
		return (error_free(message_bus, ERROR_MUTEX_HEAD));
	if (pthread_mutex_init(&message_bus->write_lock, NULL) != EXIT_SUCCESS)
		return (error_free(message_bus, ERROR_MUTEX_WRITE));
	message_bus->tail = message_bus->buffer_start;
	message_bus->head = message_bus->buffer_start;
	return (EXIT_SUCCESS);
}

// int32_t	message_bus_init(void)
// {
// 	t_s_message_bus	*message_bus;
// 	size_t			size_buffer;
//
// 	message_bus = message_bus_get();
// 	if (pthread_mutex_init(&message_bus->lock, NULL) != EXIT_FAILURE)
// 		return (EXIT_FAILURE);
// 	size_buffer = MESSAGE_BUS_SIZE * sizeof(*message_bus->buffer_start);
// 	message_bus->size = 0;
// 	message_bus->buffer_end = message_bus->buffer_start + size_buffer;
// 	message_bus->cursor_start = message_bus->buffer_start;
// 	message_bus->cursor_end = message_bus->buffer_start;
// 	return (EXIT_SUCCESS);
// }
