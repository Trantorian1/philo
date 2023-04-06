/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_promise.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:12:58 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/06 18:14:59 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PROMISE_H
# define S_PROMISE_H

# include <pthread.h>
# include <stdbool.h>

typedef struct s_promise
{
	bool		locked;
	pthread_t	fork_keft;
	pthread_t	fork_right;
}	t_s_promise;

#endif // !DEBUG
