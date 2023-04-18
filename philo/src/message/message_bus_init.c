/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bus_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:30:57 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/18 09:43:48 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_bus_init.h"

#include <stdlib.h>

#include "message_bus_get.h"

#define ERROR_MUTEX_HEAD 1
#define ERROR_MUTEX_WRITE 2
#define ERROR_MUTEX_FLUSH 3
#define ERROR_MUTEX_SIZE 4

static int32_t	error_free(t_s_message_bus *message_bus, int32_t error_code)
{
	if (error_code >= ERROR_MUTEX_HEAD)
		pthread_mutex_destroy(&message_bus->lock_tail);
	if (error_code >= ERROR_MUTEX_WRITE)
		pthread_mutex_destroy(&message_bus->lock_head);
	if (error_code >= ERROR_MUTEX_FLUSH)
		pthread_mutex_destroy(&message_bus->lock_write);
	if (error_code >= ERROR_MUTEX_SIZE)
		pthread_mutex_destroy(&message_bus->lock_flush);
	return (EXIT_FAILURE);
}

int32_t	message_bus_init(void)
{
	t_s_message_bus	*message_bus;

	message_bus = message_bus_get();
	if (pthread_mutex_init(&message_bus->lock_tail, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&message_bus->lock_head, NULL) != EXIT_SUCCESS)
		return (error_free(message_bus, ERROR_MUTEX_HEAD));
	if (pthread_mutex_init(&message_bus->lock_write, NULL) != EXIT_SUCCESS)
		return (error_free(message_bus, ERROR_MUTEX_WRITE));
	if (pthread_mutex_init(&message_bus->lock_flush, NULL) != EXIT_SUCCESS)
		return (error_free(message_bus, ERROR_MUTEX_FLUSH));
	if (pthread_mutex_init(&message_bus->lock_size, NULL) != EXIT_SUCCESS)
		return (error_free(message_bus, ERROR_MUTEX_SIZE));
	message_bus->tail = message_bus->buffer_start;
	message_bus->head = message_bus->buffer_start;
	return (EXIT_SUCCESS);
}
