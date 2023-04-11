/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_init.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:01:43 by                   #+#    #+#             */
/*   Updated: 2023/04/10 16:02:10 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_INIT_H
# define MONITOR_INIT_H

# include <stddef.h>
# include <stdint.h>

# include "f_runner.h"

int32_t	monitor_init(size_t size, t_f_runner *runner);

#endif
