/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   promise_create.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:26:24 by                   #+#    #+#             */
/*   Updated: 2023/04/10 14:26:56 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMISE_CREATE_H
# define PROMISE_CREATE_H

# include <pthread.h>

# include "s_promise.h"

t_s_promise	*promise_create(
	pthread_mutex_t *fork_left,
	pthread_mutex_t *fork_right);

#endif
