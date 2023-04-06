/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_table.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:15:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/06 18:19:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_TABLE_H
# define S_TABLE_H

# include "s_philo.h"

typedef struct s_table
{
	t_s_philo	*neighbour_left;
	t_s_philo	*neighbour_right;
}	t_s_table;

#endif // !DEBUG
