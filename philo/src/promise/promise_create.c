/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   promise_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:24:53 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 14:29:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "promise_create.h"

#include <stdbool.h>
#include <stdlib.h>

t_s_promise	*promise_create(
	pthread_mutex_t *fork_left,
	pthread_mutex_t *fork_right)
{
	t_s_promise	*promise;

	if (fork_left == NULL || fork_right == NULL)
		return (NULL);
	promise = malloc(sizeof(*promise));
	if (promise == NULL)
		return (NULL);
	promise->locked = false;
	promise->fork_left = fork_left;
	promise->fork_right = fork_right;
	return (promise);
}
