/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_promise.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:12:58 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 14:29:14 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PROMISE_H
# define S_PROMISE_H

# include <pthread.h>
# include <stdbool.h>

// TODO: This might need lock mutex instead of just 'locked' bool
typedef struct s_promise
{
	bool			locked;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
}	t_s_promise;

#endif // !DEBUG
