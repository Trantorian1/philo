/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_get_left.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:07:27 by                   #+#    #+#             */
/*   Updated: 2023/04/13 11:07:47 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_GET_LEFT_H
# define TABLE_GET_LEFT_H

# include <stdint.h>

# include "s_philo.h"
# include "s_table.h"

t_s_philo	*table_get_left(t_s_table *table, int32_t seat);

#endif
