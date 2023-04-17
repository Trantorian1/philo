/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_millis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:43:19 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 11:47:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_millis.h"

#include <stdlib.h>
#include <sys/time.h>

int32_t	time_millis(int64_t *dst)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	*dst = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (EXIT_SUCCESS);
}
