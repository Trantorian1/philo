/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:24:35 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/14 10:30:56 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_get.h"

#include <stdlib.h>

t_s_monitor	*monitor_get(void)
{
	static t_s_monitor	monitor = {.ticket_next = 0, .ticket_curr = 0};

	return (&monitor);
}
