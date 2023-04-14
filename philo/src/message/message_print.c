/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:57:31 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/14 18:45:59 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_print.h"

#include <stdlib.h>
#include <unistd.h>

#include "e_philo_state.h"
#include "message_format_nothing.h"
#include "message_format_pick_fork.h"
#include "message_format_eating.h"
#include "message_format_sleeping.h"
#include "message_format_thinking.h"
#include "message_format_dead.h"

typedef void					(*t_f_formatter_msg)(t_s_message *);

static const t_f_formatter_msg	g_formatters[E_PHILO_STATE_SIZE + 1] = {
	&message_format_nothing,
	&message_format_pick_fork,
	&message_format_eating,
	&message_format_sleeping,
	&message_format_thinking,
	&message_format_dead,
	&message_format_nothing,
	&message_format_nothing
};

int32_t	message_print(t_s_message *message)
{
	if (message == NULL)
		return (EXIT_FAILURE);
	g_formatters[message->state](message);
	return (EXIT_SUCCESS);
}
