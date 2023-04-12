/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_format_pick_fork.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:13:33 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/11 19:19:02 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_format_pick_fork.h"

#include "libft.h"

// BUG: shouls use another function that ft_putnbr_fd so as to correctly handle
// the entirety of size_t range
void	message_format_pick_fork(t_s_message *message)
{
	ft_putnbr_fd((int32_t)message->id, STDOUT_FILENO);
	ft_putendl_fd(" has picked up a fork", STDOUT_FILENO);
}
