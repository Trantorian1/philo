/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bus_get_head.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:25:45 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/11 17:20:07 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_bus_get_head.h"

#include "message_bus_get.h"

t_s_message	*message_bus_get_head(void)
{
	t_s_message_bus	*message_bus;
	t_s_message		*head;

	message_bus = message_bus_get();
	pthread_mutex_lock(&message_bus->lock_head);
	head = message_bus->head;
	pthread_mutex_unlock(&message_bus->lock_head);
	return (head);
}
