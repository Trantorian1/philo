/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:17:35 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 16:21:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_time.h"

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

int32_t	error_time(void)
{
	ft_putendl_fd("Time error", STDOUT_FILENO);
	return (EXIT_FAILURE);
}
