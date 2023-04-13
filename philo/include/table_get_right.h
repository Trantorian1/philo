/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_get_right.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:10:44 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/13 11:10:47 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_GET_RIGHT_H
# define TABLE_GET_RIGHT_H

# include <stddef.h>

# include "s_philo.h"
# include "s_table.h"

t_s_philo	*tables_get_right(t_s_table *table, int32_t seat);

#endif
