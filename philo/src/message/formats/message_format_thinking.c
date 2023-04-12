/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_format_thinking.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:16:59 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/12 10:58:07 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_format_thinking.h"

#include "libft.h"

// BUG: shouls use another function that ft_putnbr_fd so as to correctly handle
// the entirety of size_t range
void	message_format_thinking(t_s_message *message)
{
	ft_putnbr_fd((int32_t)message->id, STDOUT_FILENO);
	ft_putendl_fd(" is thinking", STDOUT_FILENO);
}
