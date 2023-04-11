/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bus_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:01:23 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/11 14:58:29 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_bus_get.h"

#include <stddef.h>
#include <stdlib.h>

/**
 * @brief Message bus singleton instance.
 *
 * @return (t_s_message_bus *): message_bus singleton instance, or NULL if an
 * error occurred.
 */
t_s_message_bus	*message_bus_get(void)
{
	static t_s_message_bus	message_bus;

	return (&message_bus);
}
