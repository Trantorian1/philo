/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bus_get_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:50:09 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/18 11:52:40 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_bus_get_size.h"

#include <pthread.h>
#include <stdlib.h>

#include "message_bus_get.h"

size_t	message_bus_get_size(void)
{
	t_s_message_bus	*message_bus;
	size_t			size;

	message_bus = message_bus_get();
	pthread_mutex_lock(&message_bus->lock_size);
	size = message_bus->size;
	pthread_mutex_unlock(&message_bus->lock_size);
	return (size);
}
