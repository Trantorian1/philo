/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_philo_state.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:17:18 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/06 18:19:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_PHILO_STATE_H
# define E_PHILO_STATE_H

typedef enum e_philo_state
{
	WAITING,
	EATING,
	THINKING,
	SLEEPING,
	E_PHILO_STATE_SIZE
}	t_e_philo_state;

#endif // !E_PHILO_STATE_H
