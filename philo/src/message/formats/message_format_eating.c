/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_format_eating.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:14:41 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/11 19:17:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_format_eating.h"

#include "libft.h"

// BUG: shouls use another function that ft_putnbr_fd so as to correctly handle
// the entirety of size_t range
void	message_format_eating(t_s_message *message)
{
	ft_putnbr_fd((int32_t)message->id, STDOUT_FILENO);
	ft_putendl_fd(" is eating", STDOUT_FILENO);
}
