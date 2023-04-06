/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bus_consume.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:46:19 by                   #+#    #+#             */
/*   Updated: 2023/04/06 18:46:19 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BUS_CONSUME_H
# define ERROR_BUS_CONSUME_H

# include <stdbool.h>
# include "s_error_bus.h"

bool	error_bus_consume(t_s_error_bus *error_bus, t_e_error_code error_code);

#endif
