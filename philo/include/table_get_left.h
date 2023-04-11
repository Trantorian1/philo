/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_get_left.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:54:20 by                   #+#    #+#             */
/*   Updated: 2023/04/10 17:55:08 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_GET_LEFT_H
# define TABLE_GET_LEFT_H

# include <stddef.h>

# include "s_philo.h"
# include "s_table.h"

t_s_philo	*table_get_left(t_s_table *table, size_t seat);

#endif
