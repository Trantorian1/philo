/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_message_bus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:58:46 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 12:53:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MESSAGE_BUS_H
# define S_MESSAGE_BUS_H

# define MESSAGE_BUS_SIZE 1024

# include <stddef.h>
# include <pthread.h>

# include "s_message.h"

typedef struct s_message_bus
{
	size_t			size;
	t_s_message		*tail;
	t_s_message		*head;
	pthread_mutex_t	lock_tail;
	pthread_mutex_t	lock_head;
	pthread_mutex_t	lock_write;
	t_s_message		buffer_start[MESSAGE_BUS_SIZE];
}	t_s_message_bus;

#endif
