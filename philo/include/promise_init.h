/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   promise_init.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:52:03 by                   #+#    #+#             */
/*   Updated: 2023/04/10 16:53:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMISE_INIT_H
# define PROMISE_INIT_H

# include <stdint.h>

# include "s_promise.h"

int32_t	promise_init(
	t_s_promise *promise,
	pthread_mutex_t *fork_left,
	pthread_mutex_t *fork_right);

#endif
