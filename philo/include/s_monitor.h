/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_monitor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:10:34 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/14 11:07:20 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MONITOR_H
# define S_MONITOR_H

# include <stdint.h>
# include <pthread.h>

typedef struct s_monitor
{
	int32_t	ticket_next;
	int32_t	ticket_curr;
	int32_t	ressources;
	pthread_mutex_t	lock_next;
	pthread_mutex_t	lock_curr;
	pthread_mutex_t	lock_ressources;
}	t_s_monitor;

#endif
