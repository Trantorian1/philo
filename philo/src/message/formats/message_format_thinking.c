/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_format_thinking.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:16:59 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 15:47:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_format_thinking.h"

#include "libft.h"

void	message_format_thinking(t_s_message *message)
{
	ft_putlong_fd(message->time, STDOUT_FILENO);
	ft_putchar_fd(' ', STDOUT_FILENO);
	ft_putnbr_fd(message->id, STDOUT_FILENO);
	ft_putendl_fd(" is thinking", STDOUT_FILENO);
}
