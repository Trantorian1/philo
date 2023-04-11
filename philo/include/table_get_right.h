/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_get_right.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:56:11 by                   #+#    #+#             */
/*   Updated: 2023/04/10 17:56:27 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_GET_RIGHT_H
# define TABLE_GET_RIGHT_H

# include <stddef.h>

# include "s_philo.h"
# include "s_table.h"

t_s_philo	*tables_get_right(t_s_table *table, size_t seat);

#endif
