/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_philo_state.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:17:18 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/14 16:56:20 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_PHILO_STATE_H
# define E_PHILO_STATE_H

typedef enum e_philo_state
{
	STATE_WAITING,
	STATE_PICK_FORK,
	STATE_EATING,
	STATE_SLEEPING,
	STATE_THINKING,
	STATE_DEAD,
	STATE_ERROR,
	E_PHILO_STATE_SIZE
}	t_e_philo_state;

#endif // !E_PHILO_STATE_H
