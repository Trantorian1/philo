/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_seat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:40:58 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 14:42:35 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_SEAT_H
# define S_SEAT_H

# include "s_philo.h"

typedef struct s_seat
{
	t_s_philo	*seated;
	t_s_philo	*neighbour_left;
	t_s_philo	*neighbour_right;
}	t_s_seat;

#endif
