/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_args.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:03:02 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 11:48:23 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_ARGS_H
# define S_ARGS_H

# include <stdint.h>

typedef struct s_args
{
	int32_t	philo_count;
	int64_t	time_death;
	int64_t	time_eat;
	int64_t	time_sleep;
	int32_t	meal_target;
}	t_s_args;

#endif
