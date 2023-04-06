/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:58:45 by                   #+#    #+#             */
/*   Updated: 2023/04/06 18:58:45 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BUS_H
# define ERROR_BUS_H

# include "s_error_bus.h"

t_s_error_bus	*error_bus(void);
void			*error_bus_destroy(void);

#endif
