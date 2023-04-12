/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_message.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:56:50 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/11 19:04:41 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MESSAGE_H
# define S_MESSAGE_H

# include <stddef.h>

# include "e_philo_state.h"

typedef struct s_message
{
	size_t			id;
	t_e_philo_state	state;
}	t_s_message;

#endif
