/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_error_bus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:23:08 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/06 19:01:34 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_ERROR_BUS_H
# define S_ERROR_BUS_H

# include <pthread.h>
# include <stdint.h>

# include "e_error_code.h"

typedef struct s_error_bus
{
	int32_t			errors[E_ERRORS_SIZE];
	pthread_mutex_t	lock;
}	t_s_error_bus;

#endif // !DEBUG
