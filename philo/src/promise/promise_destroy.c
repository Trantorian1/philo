/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   promise_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:29:40 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 14:36:21 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "promise_destroy.h"

#include <stdlib.h>

void	*promise_destroy(t_s_promise *promise)
{
	if (promise == NULL)
		return (NULL);
	promise->fork_right = NULL;
	promise->fork_left = NULL;
	free(promise);
	return (NULL);
}
