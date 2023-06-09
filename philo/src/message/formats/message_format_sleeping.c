/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_format_sleeping.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:15:39 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 15:47:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_format_sleeping.h"

#include "libft.h"

void	message_format_sleeping(t_s_message *message)
{
	ft_putlong_fd(message->time, STDOUT_FILENO);
	ft_putchar_fd(' ', STDOUT_FILENO);
	ft_putnbr_fd(message->id, STDOUT_FILENO);
	ft_putendl_fd(" is sleeping", STDOUT_FILENO);
}
