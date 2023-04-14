/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_format_dead.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:43:53 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/14 18:45:24 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_format_dead.h"

#include "libft.h"

void	message_format_dead(t_s_message *message)
{
	ft_putnbr_fd(message->id, STDOUT_FILENO);
	ft_putendl_fd(" died", STDOUT_FILENO);
}
