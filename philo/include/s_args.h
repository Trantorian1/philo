/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_args.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:03:02 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/13 17:29:28 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_ARGS_H
# define S_ARGS_H

# include <stdint.h>

typedef struct s_args
{
	int32_t		philo_count;
	uint64_t	time_death;
	uint64_t	time_eat;
	uint64_t	time_sleep;
	int64_t		meal_target;
}	t_s_args;

#endif
