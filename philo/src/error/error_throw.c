/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_throw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:26:44 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/12 10:27:49 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_throw.h"

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>

int32_t	error_throw(char *message)
{
	ft_putendl_fd(message, STDOUT_FILENO);
	return (EXIT_FAILURE);
}
