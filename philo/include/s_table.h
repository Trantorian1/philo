/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_table.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:15:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 16:25:29 by emcnab           ###   ########.fr       */
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
	int64_t			time_start;
	t_e_game_state	game_state;
	t_s_args		*args;
	t_s_philo		*guests;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*lock_request;
	pthread_mutex_t	*lock_state;
}	t_s_table;

#endif // !DEBUG
