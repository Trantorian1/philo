/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_monitor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:22:02 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/10 15:47:36 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MONITOR_H
# define S_MONITOR_H

# include "s_table.h"
# include "s_promise.h"

typedef struct s_monitor
{
	t_s_table	*table;
	t_s_promise	*promises;
}	t_s_monitor;

#endif // !DEBUG
