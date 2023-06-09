/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_table.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:15:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/21 16:12:57 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_TABLE_H
# define S_TABLE_H

# include <stdint.h>

# include "s_philo.h"
# include "s_args.h"
# include "e_game_state.h"

typedef struct s_table
{
	int32_t			size;
	int32_t			ready;
	int64_t			time_start;
	int64_t			time_curr;
	t_e_game_state	game_state;
	bool			init_state;
	bool			init_ready;
	bool			init_time;
	pthread_mutex_t	lock_state;
	pthread_mutex_t	lock_ready;
	pthread_mutex_t	lock_time;
	t_s_args		*args;
	t_s_philo		*guests;
	pthread_mutex_t	*forks;
}	t_s_table;

#endif // !DEBUG
