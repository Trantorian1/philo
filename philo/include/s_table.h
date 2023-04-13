/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_table.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:15:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/13 16:46:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_TABLE_H
# define S_TABLE_H

# include <stdint.h>

# include "s_philo.h"
# include "e_game_state.h"

typedef struct s_table
{
	int32_t			size;
	uint32_t		next_in_line;
	t_e_game_state	game_state;
	t_s_philo		*guests;
	pthread_mutex_t	*forks;
	uint64_t		*timers;
}	t_s_table;

#endif // !DEBUG
